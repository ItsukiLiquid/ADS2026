#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap{
    vector<long long> a;
    long long parent(long long i) {return (i - 1)/2;}
    long long left(long long i) {return 2*i+1;}
    long long right(long long i) {return 2*i+2;}
    long long getMax() {return (a.size() != 0) ? a[0] : -1;}
    void push(long long val){
        a.push_back(val);
        long long idx = a.size() - 1;
        while (idx > 0 && a[idx] > a[parent(idx)]){
            swap(a[idx], a[parent(idx)]);
            idx = parent(idx);
        }
    }
    void heapify(long long i){
        if (left(i) > a.size() - 1) return;
        long long j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)]){
            j = right(i);
        }
        if (a[i] < a[j]){
            swap(a[i], a[j]);
            heapify(j);
        }
    }
    long long extractMax(){
        long long root_val = getMax();
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0) heapify(0);
        return root_val;
    }
    void print(){for (long long b: a) cout << b << " ";}
};

int main(){
    long long n, k, val;
    cin >> n >> k;
    MaxHeap* heap = new MaxHeap();
    for (long long i = 0; i < n; ++i){
        cin >> val;
        heap->push(val);
    }
    long long ans = 0;
    for (long long i = 0; i < k; ++i){
        // cout << "before: ";
        // heap->print();
        long long a = heap->extractMax();
        // cout << ", a: " << a << ", extracted: ";
        // heap->print();
        ans += a;
        heap->push(a - 1);
        // cout << ", after: ";
        // heap->print();
        // cout << endl;
    }
    cout << ans;
    return 0;
}
