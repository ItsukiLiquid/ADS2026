#include <iostream>
#include <vector>
#include <utility>
using namespace std;
struct MinHeap{
    vector<long long> a;
    long long parent(long long i){return (i - 1)/2;}
    long long left(long long i){return 2*i + 1;}
    long long right(long long i){return 2*i + 2;}
    long long getMin(){return (a.size() != 0) ? a[0] : -1;}
    long long size() {return a.size();}
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
    void print(){
        if (a.size() == 0) cout << "empty";
        else{
            for (long long b: a) cout << b << " ";
        }
    }
};
int main(){
    long long q, k, val;
    long long sum = 0;
    string cmd;
    MinHeap* heap = new MinHeap();
    cin >> q >> k;
    for (long long i = 0; i < q; ++i){
        cin >> cmd;
        if (cmd == "insert"){
            cin >> val;
            if (heap->size() >= k){
                if (val >= heap->getMin()){
                    long long a = heap->extractMin();
                    sum -= a;
                    sum += val;
                    heap->push(val);
                    // cout << "replaced value " << a << " -> " << val;
                }
                // else cout << "emitted value less than getMin(): " << val; // debug only
            }
            else{
                sum += val;
                heap->push(val);
                // cout  << "added value " << val;
            }
            // cout << ", arr: ";
            // heap->print();
            // cout << endl;
        }
        else{
            // cout << "arr: ";
            // heap->print();
            cout << sum << endl;
        }
    }
    return 0;
}
