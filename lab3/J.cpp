#include <iostream>
#include <vector>
using namespace std;

struct Sheep{
    int x1, y1, x2, y2;
    Sheep (int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
};

int sheepFitQuantity(const vector<Sheep>& arr, int sq_size){
    int count = 0;
    for (const Sheep& sheep: arr){
        if (sheep.x2 <= sq_size && sheep.y2 <= sq_size) count++;
    }
    return count;
}

int minSqSize(const vector<Sheep>& arr, int max_val, int k){
    int l = 0;
    int r = max_val; // max coordinate of the all sheeps
    while (l + 1 < r){
        int mid = l + (r - l) / 2;
        if (sheepFitQuantity(arr, mid) < k) l = mid;
        else r = mid;
    }
    return r;
}

int main(){
    int n, k, x1, x2, y1, y2;
    cin >> n >> k;
    vector<Sheep> arr;
    int max_coordinate = 0;
    for (int i = 0; i < n; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        max_coordinate = max(max_coordinate, max(x1, max(x2, max(y1, y2))));
        Sheep s (x1, y1, x2, y2);
        arr.push_back(s);
    }
    cout << minSqSize(arr, max_coordinate, k);
    return 0;
}
