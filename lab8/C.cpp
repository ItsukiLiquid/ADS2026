#include <iostream>
#include <vector>
using namespace std;
using ull = unsigned long long;

ull get_hash(string& s){
    const int p = 29;
    const ull M = 1e+9;
    ull h = 0;
    ull p_pow = 1; // p^0
    for (int i = 0; i < s.size(); ++i){
        h += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<ull> get_h(string& s){
    vector<ull> h(s.size());
    h[0] = s[0] - 'a' + 1;
    const int p = 29;
    ull p_pow = 29; // we start from i = 1
    for (int i = 1; i < s.size(); ++i){
        h[i] = h[i-1] + (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return h;
}

ull hashes(string s, string pattern){
    ull result = 0;
    vector<ull> cum_hash1 = get_h(s);
    ull hash2 = get_hash(pattern);
    int n = s.size();
    int m = pattern.size();
    vector<ull> power(n);
    power[0] = 1;
    for (int i = 1; i < n; ++i){
        power[i] = power[i-1] * 29;
    }
    for (int i = 0; i < n - m + 1; ++i){
        int j = i + m - 1;
        ull window_hash = cum_hash1[j];
        if (i > 0) window_hash = window_hash - cum_hash1[i-1];
        if (window_hash == hash2 * power[i]){
            result++;
        }
    }
    return result;
}

int main(){
    // // this is for debugging
    // int n;
    // cin >> n;
    // if (n == 2){
    //     cout << 4 << endl << "aba" << endl << 2 << endl << "alpha" << endl << "haha";
    //     return 0;
    // }
    string s, pattern;
    int patternSize;
    cin >> patternSize;
    while (patternSize != 0){
        ull max_count = 0;
        vector<pair<string, ull>> patterns = {};
        for (int i = 0; i < patternSize; ++i){
            cin >> pattern;
            patterns.push_back(make_pair(pattern, 0)); // for now 0 occurencies
        }
        cin >> s;
        for (pair<string, ull>& pattern: patterns){
            ull cnt = hashes(s, pattern.first);
            pattern.second = cnt;
            if (cnt > max_count) max_count = cnt;
        }
        cout << max_count << endl;
        for (pair<string, ull>& pattern: patterns){
            if (pattern.second == max_count) cout << pattern.first << endl;
        }
        cin >> patternSize;
    }
    return 0;
}
