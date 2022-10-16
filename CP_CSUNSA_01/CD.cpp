#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Stores the CDs (represented as integers) in a vector
vector<int> storeCDNumbers(const int size) {
    // Initializing variable, used to place the current CD into cds
    int cdNum;

    // Initializing container, stores owner's complete collection of CDs
    vector<int> cds(size, 0);

    // Stores owner's CDs into cds
    for(int i = 0; i < size; i++) {
        cin >> cdNum;
        cds[i] = cdNum;
    }

    // Returns owner's container of CDs
    return cds;
}

int main(int argc, char** argv) {
    /* Initializing variables, 
     * 
     * set1Size, set2Size, stores the number of CDs Jack and Jill own, respectively
     */
    int set1Size, set2Size;

    /* Initializing containers, 
     * 
     * cdSet1, cdSet2, stores the CDs (represented as integers) owned by Jack and Jill, respectively
     */
    vector<int> cdSet1, cdSet2;

    /* Continues through each sub-test case until we reach the terminanting condition.
     * Prints the number of common CDs for the current test case before continuing 
     * to the next (potential) one.
     */
    while(cin >> set1Size >> set2Size && (set1Size != 0 && set2Size != 0)) {
        // Storing CDs Jack owns
        cdSet1 = storeCDNumbers(set1Size);

        // Storing CDs Jill owns
        cdSet2 = storeCDNumbers(set2Size);

        // Creating new vector to store the common CDs the two own
        vector<int> common(set1Size + set2Size);

        /* Storing the common elements between the two sorted ranges in common
         * Returns an iterator for common that points to the last common element found between the two sets
         */
        vector<int>::iterator lastIt = set_intersection(cdSet1.begin(), cdSet1.end(), cdSet2.begin(), cdSet2.end(), common.begin());

        // Removing unused spaces from common
        common.resize(lastIt - common.begin());

        // Outputting the number of common CDs the two own
        cout << common.size() << endl;
    }
    
    return 0;
}