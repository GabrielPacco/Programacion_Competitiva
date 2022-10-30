//Problem C
//Ants
/*  
Input
The first line of input contains one integer giving the number of cases that follow, 
at most 100. The data for each case start with two integer numbers: the length  of 
the pole (in cm) and , the number of ants residing on the pole. These two numbers 
are followed by  integers giving the position of each ant on the pole as the distance 
measured from the left end of the pole, in no particular order. All input integers are 
between 0 and 1 000 000 and they are separated by whitespace.

Output
For each case of input, output two numbers separated by a single space. The first number 
is the earliest possible time when all ants fall off the pole (if the directions 
of their walks are chosen appropriately) and the second number is the latest possible such time.

Input
2
10 3
2 6 7
214 7
11 12 7 13
176 23 191

Output
4 8
38 207

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);  // cin is faster than scanf
    ios::sync_with_stdio(false);  

    int cases;  // number of cases
    cin >> cases;  // read number of cases
    for (int i = 0; i < cases; i++) {  // for each case
        int poleLength;  // length of the pole
        int ants;  // number of ants
        cin >> poleLength >> ants;  // read length of the pole and number of ants
        vector<int> v;  // vector of ants
        for (int j = 0; j < ants; j++) {  // for each ant
            int ant;  // ant position
            cin >> ant;  // read ant position
            v.push_back(ant);  // add ant position to vector
        }
        int minTime = 0;  // minimum time
        int maxTime = 0;  // maximum time
        for (int k = 0; k < v.size(); k++) {  // for each ant
            int ant = v[k];  // ant position
            int min = std::min(ant, poleLength - ant);  // minimum time
            int max = std::max(ant, poleLength - ant);  // maximum time
            if (min > minTime) {  // if the minimum time is bigger
                minTime = min;  // update minimum time
            }
            if (max > maxTime) {  // if the maximum time is bigger
                maxTime = max;  // update maximum time
            }
        }
        cout << minTime << " " << maxTime << "\n";  // print minimum and maximum time
    }
    return 0;
}
