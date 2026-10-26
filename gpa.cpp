#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Subject{
    public:
    string name;
    double gpa;
    int credit;
    double pts;
};

double to_gpa(double pts){
    if (pts >= 95) return 4;
    if (pts < 95 && pts >= 90) return 3.67;
    if (pts < 90 && pts >= 85) return 3.33;
    if (pts < 85 && pts >= 80) return 3;
    if (pts < 80 && pts >= 75) return 2.67;
    if (pts < 75 && pts >= 70) return 2.33;
    if (pts < 70 && pts >= 65) return 2;
    if (pts < 65 && pts >= 60) return 1.67;
    if (pts < 60 && pts >= 55) return 1.33;
    if (pts < 55 && pts >= 50) return 1;
    if (pts < 50) return 0; // F
}

double GPA(vector<Subject>& gpas){
    int total_cred = 0;
    double total_gpa = 0;
    for (Subject& subj: gpas){
        int cur_cred = subj.credit;
        double cur_gpa = subj.gpa;
        if (cur_gpa == 0) continue;
        total_gpa += cur_gpa * cur_cred;
        total_cred += cur_cred;
    }
    return (double)total_gpa/total_cred;
}


bool cmp(Subject& s1, Subject& s2){
    if (s1.pts != s2.pts) return s1.pts > s2.pts;
    if (s1.gpa != s2.gpa) return s1.gpa > s2.gpa;
    if (s1.credit != s2.credit) return s1.credit > s2.credit;
    return s1.name < s2.name;
}
int main(){
    int n, cred; cin >> n;
    double pts;
    vector<Subject> v = {};
    string subj;
    for (int i = 0; i < n; ++i){
        cin >> subj >> pts >> cred;
        v.push_back({subj, to_gpa(pts), cred, pts});
    }
    sort(v.begin(), v.end(), cmp);
    cout << "Subjects (total " << n << "): " << '\n';
    for (Subject& s: v) cout << "Name: " << s.name << "               points: " << s.pts << "               gpa: " << s.gpa << '\n';
    cout << "Total GPA: " << fixed << setprecision(2) << GPA(v);

    return 0;
}


// input format:
// 11
// PP1 100 4
// Calculus_1 97.5 3
// English 96.5 3
// History 92 3
// Linear_Algebra 100 3
// ICT 85 3
// PP2 100 4
// Calculus_2 96 3
// English 95 3
// Sociology 97 5
// Discrete_Structures 100 3

// output format:

// Subjects (total 11): 
// Name: PP1               points: 100               gpa: 4
// Name: PP2               points: 100               gpa: 4
// Name: Discrete_Structures               points: 100               gpa: 4
// Name: Linear_Algebra               points: 100               gpa: 4
// Name: Calculus_1               points: 97.5               gpa: 4
// Name: Sociology               points: 97               gpa: 4
// Name: English               points: 96.5               gpa: 4
// Name: Calculus_2               points: 96               gpa: 4
// Name: English               points: 95               gpa: 4
// Name: History               points: 92               gpa: 3.67
// Name: ICT               points: 85               gpa: 3.33
// Total GPA: 3.92
