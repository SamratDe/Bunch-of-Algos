# include <vector>
# include <utility>
# include <queue>
using namespace std;

int n;
vector<vector<int> > capacity;
vector<vector<int> > adj;

int bfs(int src, int sink, vector<int> &par) {
  fill(begin(par), end(par), -1);
  par[src] = -2;
  queue<pair<int, int> > q;
  q.push({s, INFINITY});
  while (!q.empty()) {
    int curr = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int v : adj[curr]) {
      if (par[v] == -1 && capacity[curr][v]) {
        par[v] = curr;
        int new_flow = min(flow, capacity[curr][v]);
        if (v == sink) return new_flow;
        q.push({v, new_flow});
      }
    }
  }
  return 0;
}

int max_flow(int src, int sink) {
  int flow = 0;
  vector<int> par(n);
  int new_flow;
  while (new_flow = bfs(src, sink, par)) {
    flow += new_flow;
    int curr = sink;
    while (curr != src) {
      int prev = par[curr];
      capacity[prev][curr] -= new_flow;
      capacity[curr][prev] += new_flow;
      curr = prev;
    }
  }
  return flow;
}
