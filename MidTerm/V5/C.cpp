#include <bits/stdc++.h>
using namespace std;
struct MinHeap{
    vector<int> a;
    bool heapStatus = true;
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    bool existsLeft(int i) {return (left(i) < a.size());}
    bool existsRight(int i) {return (right(i) < a.size());}
    void isHeap(int i){
        // initial position is 0
        if (existsLeft(i) && existsRight(i)){
            if (a[left(i)] < a[i] || a[right(i)] < a[i]) heapStatus = false;
        }
        else if (existsLeft(i)) {
            if (a[left(i)] < a[i]) heapStatus = false;
        }
        else if (existsRight(i)){
            if (a[right(i)] < a[i]) heapStatus = false;
        }
        else return;
        isHeap(left(i));
        isHeap(right(i));
    }
};
int main() {
    int n; cin >> n;
    MinHeap* heap = new MinHeap();
    vector<int> a(n);
    for (int& x: a) cin >> x;
    heap->a = a;
    heap->isHeap(0);
    if (heap->heapStatus) cout << "YES";
    else cout << "NO";
    return 0;
}
