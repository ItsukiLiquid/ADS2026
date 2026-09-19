#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int hours(vector<int>& arr, int speed){
    int result = 0;
    for (int i = 0; i < arr.size(); ++i){
        // cout << speed << " " << arr[i] << " ";
        double div = (double)arr[i] / speed;
        // cout << div << endl;
        result += ceil(div);
    }
    // cout << endl << endl << "Total hours: ";
    return result;
}

int firstME(vector<int>& arr, int sheriff_cd){
    int l = -1;
    int r = *max_element(arr.begin(), arr.end());
    while (l + 1 < r){
        int mid = l + (r - l) / 2; // mid is a speed of robin hood, we need to find the smallest speed
        if (hours(arr, mid) <= sheriff_cd) r = mid;
        else l = mid;
    }
    return r;
}

int main(){
    int n, val, s;
    cin >> n >> s;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    cout << firstME(arr, s);
    return 0;