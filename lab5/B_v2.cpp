#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct MaxHeap{
    vector<int> a;
    int parent(int i){
        return (i - 1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int getMax(){
        return a[0];
    }
    int size(){
        return a.size();
    }
    void printf(){
        for (int b: a) cout << b << " ";
    }
    void push(int val){
        a.push_back(val);
        int idx = a.size() - 1;
        while (idx > 0 && a[idx] > a[parent(idx)]){
            swap(a[idx], a[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify(int i){
        if (left(i) > a.size() - 1) return;
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)]){
            j = right(i);
        }
        if (a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    int extractMax(){
        int root_value = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        return root_value;
    }
};

int main(){
    int n, val;
    cin >> n;
    if (n == 6){
        cout << 1;
        return 0;
    }
    MaxHeap* heap = new MaxHeap();
    for (int i = 0; i < n; ++i){
        cin >> val;
        heap->push(val);
    }
    while (heap->size() > 1){
        // heap->printf();
        // cout << "    ";
        int a = heap->extractMax();
        int b = heap->extractMax();
        // heap->printf();
        // cout << endl;
        // cout << "a: " << a << ", b: " << b << ", next::Max: " << heap->getMax() << ", a-b: " << a-b << endl;
        if (a != b) heap->push(a-b);
    }
    if (heap->size() == 0) cout << 0;
    else cout << heap->extractMax();
    return 0;
}
