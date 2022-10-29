// What Goes Up
#include <cstdio>
#include <iostream>
using namespace std;

#define MAXN 100000  // maximum number of elements in the sequence
int n, X[MAXN], M[MAXN], P[MAXN], S[MAXN];  // n = number of elements in the sequence, X = sequence, M = LIS, P = predecessor, S = stack

int main(){
    for (n=0; cin>>X[n]; n++);  // read sequence
    int l = 0;  // length of LIS
    for (int i=0; i<n; i++) {  // for each element in the sequence
        int lo=1, hi=l;  // binary search
        while (lo<=hi) {   // find position of X[i] in M
            int mid = (lo+hi+1)>>1; // mid = middle position
            if (X[M[mid]] < X[i])  // X[i] is larger than X[M[mid]]
                lo = mid+1;   // search in the right half
            else   // X[i] is smaller than X[M[mid]]
                hi = mid-1;   // search in the left half
        }

        P[i] = M[lo-1];  // predecessor of X[i] is X[M[lo-1]]
        M[lo] = i;     // X[i] is the last element of a LIS of length lo
        if (lo > l) l = lo;   // update length of LIS
    }

    printf("%d\n-\n", l);  // print length of LIS

    int k = M[l];   // last element of LIS
    for (int i=l-1; i>=0; i--) {  // for each element in the LIS
        S[i] = X[k];  // store element in stack
        k = P[k];   // go to predecessor
    }

    for (int i=0; i<l; i++)  // print LIS
        cout << S[i] << endl; // print element
}
