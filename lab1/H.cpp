#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, age;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; ++i){
        cin >> age;
        // instantly check the stack
        while (!st.empty() && st.top() >= age) st.pop(); // we remove all preceding upper numbers untill the nearest least found
        if (st.empty()) cout << -1 <<  " "; // no least elements, trivial for first element
        else cout << st.top() << " "; // the nearest smallest age
        st.push(age); // finally push age to the stack
    }
    return 0;
}