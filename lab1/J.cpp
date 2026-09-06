#include <iostream>
#include <deque>
using namespace std;

// for debugging
string show_deque(deque<int>& dq){
    string result = "";
    for (int i = 0; i < dq.size(); ++i){
        result = result + to_string(dq.front()) + ' ';
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return result;
}

bool boris_wins(int boris_card, int nursik_card){
    if (boris_card == 9 && nursik_card == 0) return false;
    if (boris_card == 0 && nursik_card == 9) return true;
    else return boris_card > nursik_card;
}

int main(){
    int counter = 0;
    int card;
    deque<int> boris;
    deque<int> nursik;
    for (int i = 0; i < 5; ++i){
        cin >> card;
        boris.push_back(card);
    }
    for (int i = 0; i < 5; ++i){
        cin >> card;
        nursik.push_back(card);
    }
    while (!boris.empty() && !nursik.empty()){
        int boris_cur_card = boris.front();
        int nursik_cur_card = nursik.front();
        if (boris_wins(boris_cur_card, nursik_cur_card)){
            // cout << counter << ". Boris: " << show_deque(boris) << ", Nursik: " << show_deque(nursik) << " -> ";
            boris.push_back(boris.front());
            boris.push_back(nursik.front());
            nursik.pop_front();
            boris.pop_front();
            // cout << "(turned)" << ". Boris: " << show_deque(boris) << ", Nursik: " << show_deque(nursik) << " (took Boris)" << endl;
        }
        else {
            // cout << counter << ". Boris: " << show_deque(boris) << ", Nursik: " << show_deque(nursik) << " -> ";
            nursik.push_back(boris.front());
            nursik.push_back(nursik.front());
            boris.pop_front();
            nursik.pop_front();
            // cout << "(turned)" << ". Boris: " << show_deque(boris) << ", Nursik: " << show_deque(nursik) << " (took Nursik)"<< endl;
        }
        counter++;
    }
    if (boris.empty()) cout << "Nursik " << counter;
    else cout << "Boris " << counter;
    return 0;
}
