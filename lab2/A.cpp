#include <iostream>
#include <queue>
using namespace std;

void first(int len){
    queue<char> letters;
    int count[26] = {};
    char letter;
    for (int i = 0; i < len; ++i){
        cin >> letter;
        letters.push(letter);
        count[letter - 'a']++;
        while (!letters.empty() && count[letters.front() - 'a'] > 1) letters.pop();
        if (letters.empty()) cout << -1 << " ";
        else cout << letters.front() << " ";
    }
    cout << endl;
}
int main(){
    int n, len;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> len;
        first(len);
    }
    return 0;
}