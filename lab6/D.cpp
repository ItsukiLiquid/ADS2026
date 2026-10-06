#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> strptime(string date){
    // dd-mm-yyyy
    // 0123456789

    int day = stoi(date.substr(0,2));
    int month = stoi(date.substr(3,2));
    int year = stoi(date.substr(6,4));
    return {day, month, year};
}

bool cmp(vector<int> d1, vector<int> d2){ // should d1 come first? true: d1 is less, false: d1 is more
    // d[0]: day, d[1]: month, d[2]: year
    if (d2[2] > d1[2]) return true; // year is bigger, immediately d1 is first
    else if (d2[2] < d1[2]) return false; // if d1.year is bigger, d2 comes first
    else{
        // same year
        if (d2[1] > d1[1]) return true;
        else if (d2[1] < d1[1]) return false;
        else{
            // same month
            if (d2[0] > d1[0]) return true;
            else if (d2[0] < d1[0]) return false;
            else return false; // no sense comparing exact dates: either one is correct
        }
    }
}

string to_date(int date){
    if (date < 10) return "0" + to_string(date);
    else return to_string(date);
}

int main(){
    int n;
    string d;
    vector<vector<int>> dates;

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> d;
        dates.push_back(strptime(d));
    }
    sort(dates.begin(), dates.end(), cmp);
    for (vector<int> date: dates){
        cout << to_date(date[0]) << '-' << to_date(date[1]) << "-" << to_date(date[2]) << endl;
    }
    return 0;
}
