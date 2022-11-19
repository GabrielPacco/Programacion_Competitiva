#include <bits/stdc++.h>
using namespace std;

constexpr int P = 10003, inf = 1e8 + 3;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<pair<int, int>> adj[P];
bool processed[P];
int64_t dis[P];
int ans = 0, p, t;  

void data_input() {
  int s, e, w;
  cin >> p >> t;
  while (t--) {
    cin >> s >> e >> w;
    adj[s].push_back({e, w});
    adj[e].push_back({s, w});
  }
}

void dfs_algoritm(int u) {
  processed[u] = true;
  for (auto v : adj[u]) {
    if (dis[v.first] + v.second == dis[u]) {
      ans += v.second;
      if (!processed[v.first])
        dfs_algoritm(v.first);
    }
  }
}

int main(int, char**){
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);

  data_input();
  
  memset(processed, false, sizeof(processed));
  fill_n(dis, p, inf);

  dis[0] = 0;
  q.push({0, 0});
  int w, u;
  while (!q.empty()) {
    w = q.top().first, u = q.top().second;
    q.pop();

    if (dis[u] < w)
      continue;

    for (auto v : adj[u]) {
      if (w + v.second < dis[v.first]) {
        dis[v.first] = w + v.second;
        q.push({dis[v.first], v.first});
      }
    }  
  }

  dfs_algoritm(p - 1);
  cout << ans * 2 << '\n';

  return 0;
}