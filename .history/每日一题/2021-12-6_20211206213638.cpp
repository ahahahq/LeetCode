#include <iostream>
using namespace std;

string truncateSentence(string s, int k) {
    int i = 0; 
    for (; i < s.size(); i++) {
        if (s[i] == ' ') k--;
        if (!k) break;
    }
    return s.substr(0, i);
}

int main() {
    string s = "Hello how are you Contestant";
    int k = 4;
    string res = truncateSentence(s, k);
    cout << res << endl;
    return 0;
}