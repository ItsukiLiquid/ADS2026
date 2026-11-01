#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    stack<int> st;
    string cmd;
    stringstream ss(s);
    while (ss >> cmd){
        if (cmd == "+" || cmd == "-" || cmd == "*" || cmd == "/"){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (cmd == "+") st.push(b + a);
            else if (cmd == "-") st.push(b - a);
            else if (cmd == "*") st.push(b * a);
            else if (cmd == "/") st.push(b / a);
        }
        else st.push(stoi(cmd));
    }
    cout << st.top();
    
    return 0;
}
