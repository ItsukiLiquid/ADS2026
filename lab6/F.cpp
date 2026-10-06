#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person{
    string lastname, firstname;
    double gpa;
};

bool cmp(const Person& p1, const Person& p2){
    if (p1.gpa != p2.gpa) return p1.gpa < p2.gpa;
    if (p1.lastname != p2.lastname) return p1.lastname < p2.lastname;
    return p1.firstname < p2.firstname;
}

double stoGPA(string s){
    if (s == "A+") return 4;
    else if (s == "A") return 3.75;
    else if (s == "B+") return 3.5;
    else if (s == "B") return 3;
    else if (s == "C+") return 2.5;
    else if (s == "C") return 2;
    else if (s == "D+") return 1.5;
    else if (s == "D") return 1;
    else return 0;
}

double gpa(vector<pair<string, int>>& gpas){
    double ans = 0;
    double cum_gpa = 0;
    int cred = 0;
    for (pair<string, int> subj: gpas){
        int cur_cred = subj.second;
        double curGPA = stoGPA(subj.first);
        cum_gpa += curGPA*cur_cred;
        cred += cur_cred;
    }
    return (double)cum_gpa / cred;
}


int main(){
    int n, val, cred;
    string lastname, firstname, gpa_letter;
    cin >> n;
    vector<Person> v;
    for (int i = 0; i < n; ++i){
        cin >> lastname >> firstname;
        cin >> val;
        vector<pair<string, int>> cur_subj;
        for (int j = 0; j < val; ++j){
            cin >> gpa_letter >> cred;
            cur_subj.push_back(make_pair(gpa_letter, cred));
        }
        double total_gpa = gpa(cur_subj);
        v.push_back({lastname, firstname, total_gpa});
    }
    sort(v.begin(), v.end(), cmp);
    for (Person& p: v) cout << p.lastname << " " << p.firstname << " " << fixed << setprecision(3) << p.gpa << endl;
    return 0;
}
