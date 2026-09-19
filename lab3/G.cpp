#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int numPieces(vector<int>& arr, double size){
    int result = 0;
    for (int i = 0; i < arr.size(); ++i){
        result += arr[i]/size;
    }
    return result;
}
double setSize(vector<int>& arr, int piece){
    double l = 0;
    double r = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < 100; ++i){
        double mid = (double)(l + (r - l) / 2);
        if (numPieces(arr, mid) >= piece) l = mid;
        else r = mid;
    }
    return r;
}
int main(){
    int n, p, val;
    cin >> n >> p;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    double maxSize = setSize(arr, p);
    cout << fixed << setprecision(9) << (double)(maxSize);
    return 0;
}