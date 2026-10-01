// solved using MinHeap struct, not priority queue

#include <iostream>
#include <vector>
#include <utility> // swap operation
using namespace std;
struct MinHeap{
    public:
    vector<long long> a;

    long long parent(long long i){
        return (i - 1)/2;
    }
    long long left(long long i){
        return 2*i + 1;
    }
    long long right(long long i){
        return 2*i + 2;
    }
    long long size(){
        return a.size();
    }
    long long getMin(){
        return a[0];
    }

    void push(long long val){
        a.push_back(val);
        long long idx = a.size() - 1;
        while (idx > 0 && a[idx] < a[parent(idx)]){ // if current is < than parent, swap
            swap(a[idx], a[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify(int i){
        if (left(i) > a.size() - 1) return; // cant find left, so stop
        long long j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)]) j = right(i);
        // if parent (a[i]) is greater than its Smallest chilf (a[j]), swap and continue
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    long long extractMin(){
        long long root_value = getMin();
        // replace root value with last max_element
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        // cout << "extracted: " << root_value << endl;
        return root_value;
    }
    void print(){
        for (long long n: a) cout << n << " ";
    }
};
int main(){
    long long n, val;
    cin >> n;
    MinHeap* heap = new MinHeap();
    for (long long i = 0; i < n; ++i){
        cin >> val;
        heap->push(val);
    }
    long long answer = 0;
    // heap->print();
    while(heap->size() > 1){
        long long a = heap->extractMin();
        long long b = heap->extractMin();
        // cout << a << " " << b << " " << a + b << endl; 
        answer += a + b;
        heap->push(a + b);
    }
    cout << answer;
    return 0;
}
