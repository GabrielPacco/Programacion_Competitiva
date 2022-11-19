#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1 << 11;

int grid[MAX][MAX];
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main(int, char**) {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);

  int c_co, avenid, street;
  while (cin >> c_co, c_co) {
    memset(grid, -1, sizeof(grid));

    queue<pair<int, int>> q_exe;
    while (c_co--) {
      cin >> avenid >> street;
      grid[avenid][street] = 0;
      q_exe.push({avenid, street});
    }

    cin >> c_co;
    while (c_co--) {
      cin >> avenid >> street;
      grid[avenid][street] = -2;
    }

    int distance = 0;
    bool there_is_path = false;
    while (!q_exe.empty() && !there_is_path) {
      auto u = q_exe.front();
      q_exe.pop();

      for (auto direction : directions) {
        pair<int, int> v = {u.first + direction.first, u.second + direction.second};
        
        if (0 <= v.first < MAX && 0 <= v.second < MAX) {
          if (grid[v.first][v.second] == -1) {
            grid[v.first][v.second] = grid[u.first][u.second] + 1;
            q_exe.push(v);
          }
          else if (grid[v.first][v.second] == -2) {
            distance = grid[u.first][u.second] + 1;
            there_is_path = true;
          }
        }
      }
    }

    cout << distance << '\n';

  }

  return 0;
}