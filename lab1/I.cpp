#include <iostream>
#include <deque>
#include <queue>
using namespace std;

void move_Pos(deque<int>& dq, int pos){
    for (int i = 0; i < pos; ++i){
        dq.push_front(dq.back());
        dq.pop_back();
    }
}
deque<int> generate_deque(int n){
    deque<int> result;
    for (int i = 1; i <= n; ++i){
        result.push_back(i);
    }
    return result;
}
deque<int> ideal_shuffle(int n){
    deque<int> init_dq = generate_deque(n);
    deque<int> result;
    for (int i = n; i > 0; --i){
        result.push_front(init_dq.back());
        init_dq.pop_back();
        // cout << result.front() << " <- result.front(), init" << 
        move_Pos(result, i);
    }
    return result;
}

int main(){
    int n, length;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> length;
        deque<int> ideal_dq = ideal_shuffle(length);
        while (!ideal_dq.empty()){
            cout << ideal_dq.front() << " ";
            ideal_dq.pop_front();
        }
        cout << endl;
    }
    
    // deque<int> gdq = generate_deque(n);
    // deque<int> dq;
    // dq.push_back(2);
    // dq.push_back(5);
    // dq.push_back(4);
    // dq.push_back(6);
    // dq.push_back(3); // 2 5 4 6 3
    // move_Pos(dq, 2); // expected 6 3 2 5 4
    // // while (!dq.empty()){
    // //     cout << dq.front() << " ";
    // //     dq.pop_front();
    // // }
    // while (!gdq.empty()){
    //     cout << gdq.front() << " ";
    //     gdq.pop_front();
    // }
    return 0;
}
