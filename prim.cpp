#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define ll long long

//	LOGIC: Add vertex to the growing spanning tree

const int N = 100001;
vector<pair<ll, int> > graph[N];
vector<bool> vis(N, false);

// MST algo
ll prim(int src) {
  priority_queue<vector<pair<ll, int> >, pair<ll, int>, greater<pair<ll, int> > > q;
  ll minCost = 0;
  q.push({0, src});
  while(!q.empty()){
    pair<ll, int> ff = q.top();
    q.pop();
    int u = ff.second;
    if (vis[u]) continue;
    vis[u] = true;
    minCost += ff.first;
    for (int i = 0; i < graph[u].size(); i++) {
      pair<ll, int> p = graph[u][i];
      int v = p.second;
      if (!vis[v]) {
        q.push(p);
      }
    }
  }
  return minCost;
}
