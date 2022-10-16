#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        map<char, int> m;
        m['B'] = m['F'] = m['P'] = m['V'] = 1;
        m['C'] = m['G'] = m['J'] = m['K'] = m['Q'] = m['S'] = m['X'] = m['Z'] = 2;
        m['D'] = m['T'] = 3;
        m['L'] = 4;
        m['M'] = m['N'] = 5;
        m['R'] = 6;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] != 0)
            {
                if (ans.size() == 0)
                {
                    ans += to_string(m[s[i]]);
                }
                else if (ans[ans.size() - 1] != to_string(m[s[i]])[0])
                {
                    ans += to_string(m[s[i]]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}