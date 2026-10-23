#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Date{
    public:
    int day, month, year;
};

Date strptime(string s){
    // 01-01-0101
    // 0123456789
    // day: 0-1, months: 3-4, year: 6-9
    int day = stoi(s.substr(0,2));
    int month = stoi(s.substr(3,2));
    int year = stoi(s.substr(6,4));
    return {day, month, year};
}


bool cmp(Date d1, Date d2){
    if (d1.year != d2.year) return d1.year < d2.year;
    else{
        if (d1.month != d2.month) return d1.month < d2.month;
        else{
            if (d1.day != d2.day) return d1.day < d2.day;
            return false; // dates are same, no change order to remove TLE or infinite identites
        }
    }


int main(){
    int n; cin >> n;
    string s;
    vector<Date> v;
    for (int i = 0; i < n; ++i){
        cin >> s;
        v.push_back(strptime(s));
    }
    sort(v.begin(), v.end(), cmp);
    for (Date& d: v){
        // if date's size is <10 (1-9), add a prefix 0
        if (d.day < 10) cout << '0' + to_string(d.day) << '-';
        else cout << d.day << '-';
        if (d.month < 10) cout << '0' + to_string(d.month) << '-';
        else cout << d.month << '-';
        cout << d.year << endl;
    }
    return 0;
}
