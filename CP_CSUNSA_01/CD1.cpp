#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> CDnums(const int tam) {
    
    int n;
    vector<int> cds(tam, 0);
    for(int i = 0; i < tam; i++) {
        cin >> n;
        cds[i] = n;
    }
    return cds;
}

int main() {

    int set1Size, set2Size;

    vector<int> cdSet1, cdSet2;

    while(cin >> set1Size >> set2Size && (set1Size != 0 && set2Size != 0)) {
        cdSet1 = CDnums(set1Size);
        cdSet2 = CDnums(set2Size);
        vector<int> common(set1Size + set2Size);
        vector<int>::iterator lastIt = set_intersection(cdSet1.begin(), cdSet1.end(), cdSet2.begin(), cdSet2.end(), common.begin());

        common.resize(lastIt - common.begin());
        cout << common.size() << endl;
    }
    
    return 0;
}
