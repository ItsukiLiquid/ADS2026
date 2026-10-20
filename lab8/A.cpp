#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
using ull = unsigned long long;

ull getHash(string s){
    ull p_pow = 1;
    ull h = 0;
    const ull M = 1000000007;
    for (int i = 0; i < s.size(); ++i){
        h = (h + ((int(s[i]) - 47) * p_pow) % M) % M;
        p_pow = (p_pow * 11) % M;
    }
    return h;
}

int main(){
    int n;
    cin >> n;
    string s;
    unordered_set<string> st;
    vector<string> v = {};
    int cnt = 0;
    for (int i = 0; i < 2*n; ++i){
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }
    for (string& s: v){
        if (cnt == n) break; // key point
        ull h = getHash(s);
        if (st.count(to_string(h))){
            cout << "Hash of string \"" << s << "\" is " << h << endl;
            cnt++;
        }
    }
    return 0;
}
