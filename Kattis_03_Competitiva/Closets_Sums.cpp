#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);  // cin is faster than scanf
    ios::sync_with_stdio(false);  
    
    int n, queri;   // number of integers in the sequence
    int count = 0;   // case number
    while (cin >> n) { 
        count++;        // update case number   
        cout << "Case " << count << ":\n";
        vector<int> v;  // vector of integers
        for (int i = 0; i < n; i++) {
            int num;    // read integer
            cin >> num;    // read integer
            v.push_back(num); // add integer to vector
        }
        sort(v.begin(), v.end());  // sort vector
        cin >> queri;  // read number of queries
        for (int l = 0; l < queri; l++) {
            int num;  // sum to find
            cin >> num; // read sum to find 
            int closestSum = 1000000000; // minimum difference
            for (int first = 0; first < v.size(); first++) {  // for each number in the sequence
                int close = 1000000000;  // minimum difference
                int num1 = v[first];   // first number
                for (int sec = first + 1; sec < v.size(); sec++) {  // for each number in the sequence
                    int num2 = v[sec];  // second number
                    if (abs(num1 + num2 - num) < abs(close - num)) { // if the difference is smaller
                        close = num1 + num2;  // update minimum difference
                    }
                    else {
                        break; // if the difference is bigger, stop searching
                    }
                }
                if (abs(close - num) < abs(closestSum - num)) {  // if the difference is smaller
                    closestSum = close; // update minimum difference
                }
            }
            cout << "Closest sum to " << num << " is " << closestSum << ".\n";
        }
    }
    return 0;
}