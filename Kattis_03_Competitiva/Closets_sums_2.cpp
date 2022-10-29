#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Closest Sums
int main()
{
    int n; // number of integers in the sequence
    int caso = 1;  // case number
    while (cin >> n) 
    {
        vector<int> v;  // vector of integers
        int buffer = 0; // buffer for reading integers
        for (int i = 0; i < n; i++)  // read integers
        {
            cin >> buffer;      // read integer
            v.push_back(buffer);  // add integer to vector
        }
        sort(v.begin(), v.end());   // sort vector
        int m;                   // number of queries
        cin >> m;              // read number of queries
        cout << "Case " << caso << ":" << '\n';   // print case number
        for (int i = 0; i < m; i++)  
        {
            int sum;   // sum to find
            cin >> sum;   // read sum to find
            int min = 1000000000;  // minimum difference
            int min1 = 0;         // first number of pair
            int min2 = 0;           // second number of pair    
            for (int j = 0; j < n; j++)   // for each number in the sequence
            {
                int k = sum - v[j];   // difference between sum and number
                if (k < 0)   // if difference is negative
                {
                    k = -k;   // make it positive
                }
                if (k < min)   // if difference is less than minimum difference
                {
                    min = k;   // update minimum difference
                    min1 = v[j];   // update first number of pair
                    min2 = sum - v[j];   // update second number of pair
                }
            }
            cout << "Closest sum to " << sum << " is " << min1 + min2 << "." << '\n';
        }
        caso++;  // update case number
    }
    return 0;
}
