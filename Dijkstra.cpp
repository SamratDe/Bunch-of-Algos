# include <vector>
# include <queue>
# include <utility>
using namespace std;

#define ll long long

// LOGIC : compares according to vertices distances. (use min priority queue)
// Q: Why doesn't work with -ve cycles ?
// Complexity: O(V + ElogV)

const int N = 100001;
vector<pair<int, int> > graph[N];
vector<ll> dist(N, INT_MAX);
vector<bool> vis(N, false);

// SP from src to all vertex
int dijkstra(int src) {
  priority_queue <pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > q;
  q.push({0, src});
  dist[src] = 0;
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i].second;
      int wt = graph[u][i].first;
      if (dist[v] > dist[u] + wt) {
        dist[v] = dist[u] + wt;
        q.push({dist[v], v});
      }
    }
  }
}
