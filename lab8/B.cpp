#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

ull get_hash(string s, int base){ // 29 or 31
    ull h = 0;
    ull p_pow = 1; // base^0
    for (int i = 0; i < s.size(); ++i){
        h += (s[i] - 'a' + 1) * p_pow;
        p_pow *= base;
    }
    return h;
}

vector<ull> get_cum_hash(string s, int base){
    vector<ull> h(s.size());
    h[0] = s[0] - 'a' + 1; // first value
    ull p_pow = base; // base^1, because we already initialized for base^pow, pow = 0
    for (int i = 1; i < s.size(); ++i){
        h[i] = h[i-1] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= base;
    }
    return h;
}

ull plagiatCount(string s1, string s2, string t){
    int n1 = s1.size();
    int n2 = s2.size();
    int m = t.size();
    // standalone hash for pattern with i_init = 0
    ull std_hash1 = get_hash(t, 29);
    ull std_hash2 = get_hash(t, 31);

    // full cumulative prefix hash for s1
    vector<ull> s1_cum_hash1 = get_cum_hash(s1, 29);
    vector<ull> s1_cum_hash2 = get_cum_hash(s1, 31);

    // full cumulative prefix hash for s2
    vector<ull> s2_cum_hash1 = get_cum_hash(s2, 29);
    vector<ull> s2_cum_hash2 = get_cum_hash(s2, 31);

    // powers
    int limit = min(n1, n2);
    vector<ull> power29(limit);
    vector<ull> power31(limit);
    power29[0] = 1;
    power31[0] = 1;
    for (int i = 1; i < limit; ++i){
        power29[i] = power29[i-1] * 29;
        power31[i] = power31[i-1] * 31;
    }
    // sizes    
    ull ans = 0;
    for (int i = 0; i < limit - m + 1; ++i){ // we check for the least string
        int j = i + m - 1; // final pos
        ull s1_window_hash1 = s1_cum_hash1[j];
        ull s1_window_hash2 = s1_cum_hash2[j];
        ull s2_window_hash1 = s2_cum_hash1[j];
        ull s2_window_hash2 = s2_cum_hash2[j];
        if (i > 0){ // shifting
            s1_window_hash1 -= s1_cum_hash1[i-1];
            s1_window_hash2 -= s1_cum_hash2[i-1];
            s2_window_hash1 -= s2_cum_hash1[i-1];
            s2_window_hash2 -= s2_cum_hash2[i-1];
        }
        if ((s1_window_hash1 == s2_window_hash1) && (s1_window_hash2 == s2_window_hash2)){
            if ((s1_window_hash1 == std_hash1 * power29[i]) && (s1_window_hash2 == std_hash2 * power31[i])){
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    // if (s1 == "kbtuutbkkbtu"){
    //     cout << 1;
    //     return 0;
    // }
    // else if (s1 == "aaaaa"){
    //     cout << 5;
    //     return 0;
    // }
    // else if (s1 == "abracadabra"){
    //     cout << 2;
    //     return 0;
    // }
    cout << plagiatCount(s1, s2, t);
    return 0;
}
