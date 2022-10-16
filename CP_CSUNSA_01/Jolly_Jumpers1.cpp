#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        bool j = true;
        int buffer = 0;
        vector<int> v;
        vector<int> v2;
        for (int i = 0; i < n; i++)
        {
            cin >> buffer;
            v.push_back(buffer);
        }
        for (int i = 0; i < n - 1; i++)
        {
            v2.push_back(abs(v[i] - v[i + 1]));
        }
        sort(v2.begin(), v2.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (v2[i] != i + 1)
            {
                j = false;
                cout << "Not jolly" << '\n';
                break;
            }
        }
        if (j)
        {
            cout << "Jolly" << '\n';
        }
    }
    return 0;
}