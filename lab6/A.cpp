#include <iostream>
#include <algorithm>
using namespace std;


bool isVowel(char letter){
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u') return true;
    return false;
}

string sortLetters(string s){
    string vowels = "";
    string consonants = "";
    for (char c: s){
        if (isVowel(c)) vowels += c;
        else consonants += c;
    }
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
    return vowels + consonants;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    cout << sortLetters(s);
    return 0;
}
