#include <iostream>
#include <vector>   
#include <algorithm>
#include <unordered_map>
using namespace std;

// Almost Union Find problem
// Competitive Programming 3
// Chapter 1.4.2

int main() {
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++) {
        p[i] = i;
    }
    string command;
    while (cin >> command) {
        if (command == "c") {
            int i, j;
            cin >> i >> j;
            p[i] = j;
        }
        else if (command == "q") {
            int i, j;
            cin >> i >> j;
            unordered_map<int, int> m;
            while (i != p[i]) {
                m[i] = 1;
                i = p[i];
            }
            while (j != p[j]) {
                if (m.count(j) == 1) {
                    cout << j << endl;
                    break;
                }
                j = p[j];
            }
        }
    }

    return 0;
}
