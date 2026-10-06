#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string oldname, newname;
    cin >> n;
    vector<pair<string, string>> v;
    for (int i = 0; i < n; ++i){
        cin >> oldname >> newname;
        bool isFound = false;
        for (pair<string, string>& p: v){
            if (p.second == oldname){
                p.second = newname;
                isFound = true;
                break;
            }
        }
        if (!isFound){
            v.push_back(make_pair(oldname, newname));
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (const pair<string, string>& p: v) cout << p.first << " " << p.second << endl;
    return 0;
}
