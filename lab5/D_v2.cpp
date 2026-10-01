#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct MinHeap{
    public:
    vector<long long> a;
    long long parent(long long i){return (i - 1)/2;}
    long long left(long long i){return 2*i+1;}
    long long right(long long i){return 2*i+2;}
    long long getMin(){return (a.size() != 0) ? a[0] : -1;}
    long long size(){return a.size();}
    void push(long long val){
        a.push_back(val);
        long long idx = a.size() - 1;
        while (idx > 0 && a[idx] < a[parent(idx)]){
            swap(a[idx], a[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify(long long i){
        if (left(i) > a.size() - 1) return;
        long long j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)]) j = right(i);
        if (a[i] > a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    long long extractMin(){
        long long root_val = getMin();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        return root_val;
    }
};
int main(){
    long long n, k, val;
    cin >> n >> k;
    MinHeap* heap = new MinHeap();
    long long counter = 0;
    for (int i = 0; i < n; ++i){
        cin >> val;
        heap->push(val);
    }
    while (heap->getMin() < k){
        if (heap->size() < 2){
            cout << -1;
            return 0;
        }
        long long a = heap->extractMin();
        long long b = heap->extractMin();
        heap->push(a + 2*b);
        counter++;
    }
    cout << counter;
    return 0;
}
