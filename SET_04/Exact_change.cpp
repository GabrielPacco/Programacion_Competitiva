#include <iostream>
#include <cstring>

using namespace std;

// Exact Change

int C[20];
int DP[10000]; // DP[i] = min coins to make change for i cents
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);   // fast input

    int ncasos, n, p;  // ncasos = number of test cases, n = number of coins, p = price
    cin >> ncasos;    // read number of test cases
    while (ncasos--) {   // for each test case
        cin >> p >> n;  // read price and number of coins
        for (int i=0; i<n; ++i)
            cin >> C[i];  // read coin

        memset(DP, 127, sizeof(DP)); // initialize DP with infinity

        DP[0] = 0; // minimum number of coins to make change for 0 cents is 0
        for (int i=0; i<n; ++i) { // for each coin
            int c = C[i];  // coin
            for (int j=p; j>=0; --j)  // for each amount of change
                DP[j+c] = min(DP[j+c], DP[j]+1); // update DP
        }
        
        int j;  // amount of change
        for (j=p; DP[j]>100; ++j);  // find minimum amount of change
        cout << j << ' ' << DP[j] << '\n'; // print minimum amount of change and minimum number of coins
    }
}