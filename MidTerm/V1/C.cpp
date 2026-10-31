#include <iostream>
#include <vector>
using namespace std;

struct MaxHeap{
    public:
    vector<int> a;
    int parent(int i) {return (i-1)/2;}
    int left(int i) {return 2*i+1;}
    int right(int i) {return 2*i+2;}
    bool isExistLeft(int i){
        return (2*i + 1 < a.size());
    }
    bool isExistRight(int i){
        return (2*i+2 < a.size());
    }
    void heapify(int i){
        while (isExistLeft(i) || isExistRight(i)){ // at least one child exists
            int largest = i;
            if (isExistLeft(i) && isExistRight(i)){ // both childs exist
              // pick the largest index through searching
                if (a[left(i)] == a[right(i)]){
                    if (a[left(i)] > a[i]){
                        largest = left(i);
                    }
                }
                else if (a[left(i)] > a[right(i)] && a[left(i)] > a[i]) {
                    largest = left(i);
                }
                else if (a[right(i)] > a[left(i)] && a[right(i)] > a[i]) {
                    largest = right(i);
                }
            }
            else if (isExistLeft(i) && a[left(i)] > a[i]) largest = left(i);
            else if (isExistRight(i) && a[right(i)] > a[i]) largest = right(i);

          // stop if parent is larger than its childs
            if (largest == i) break;
          // if no, swap with child, not Tartaglia!
            swap(a[largest], a[i]);
          // mark the next heapifying position
            i = largest;
        }
    }
    void buildHeap(){
        for (int i = a.size()/2 - 1; i >= 0; --i) heapify(i);
    }
    void print(){
        for (int& elem: a) cout << elem << " ";
    }
};

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for (int& x: v) cin >> x;
    MaxHeap* heap = new MaxHeap();
    heap->a = v;
    heap->buildHeap();
    heap->print();

    return 0;
}
