#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string s;  // input string
int vals, p;  // vals = number of variables, p = position in input string
bool calc() {
    char ch = s[p++];  // read next character
    switch (ch) {    // switch on character
        case 'p': case 'q':
        case 'r': case 's': case 't':
            return (1<<(ch-'p')) & vals;  // return value of variable
        case 'N': return !calc();
        case 'E': return  calc() ==calc();
        case 'K': return  calc() & calc();
        case 'A': return  calc() | calc();
        case 'C': return !calc() | calc();
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> s && s[0]!='0') {    // read input string
        for (vals=(1<<5)-1; vals>=0; --vals) {   // for each combination of variables
            p = 0;  // reset position in input string
            if (!calc()) {  // if expression is false
                cout << "not\n";  // print not
                goto fin;  // go to next test case
            }
        }
        cout << "tautology\n";
        fin:;   // end
    }
}