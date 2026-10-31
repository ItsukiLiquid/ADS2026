#include <bits/stdc++.h>
using namespace std;
struct MaxHeap{
    vector<int> a;
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    void push(int val){
        a.push_back(val);
        int idx = a.size() - 1;
        while (idx > 0 && a[idx] > a[parent(idx)]){
            swap(a[idx], a[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify(int i){
        if (left(i) >= a.size()) return;
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] < a[right(i)]) j = right(i);

        if (a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    int getMax() {return (a.empty()) ? -1 : a[0];}
    int extractMax(){
        int root = getMax();
        swap(a[0], a[a.size()-1]);
        a.pop_back();
        if (!a.empty()) heapify(0);
        return root;
    }
};
int main() {
    int n, val; cin >> n;
    MaxHeap* heap = new MaxHeap();
    for (int i = 0; i < n; ++i){
        cin >> val;
        heap->push(val);
    }
    while (heap->a.size() > 1){
        int a = heap->extractMax();
        int b = heap->extractMax();
        if (a != b) heap->push(a - b);
    }
    if (heap->a.size() == 0) cout << 0;
    else cout << (heap->getMax());
    return 0;
}
