#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define ll long long

// LOGIC :
// builds the spanning tree by ADDING EDGES one by one into a growing spanning tree,
// in each iteration it finds an edge which has least weight (GREEDY)
// add it to the growing spanning tree. (while checking that edges don't form a cycle)

const int N = 100001;
vector<pair<ll, pair<int, int> > > edges;
vector<int> par(N), sz(N);

// dsu by size
void init() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}

int find(int x) {
  if (par[x] != x) par[x] = find(par[x]);
  return par[x];
}

void merge(int x, int y) {
  int xr = find(x), yr = find(y);
  if (xr == yr) return;
  if (sz[xr] >= sz[yr]) {
    par[yr] = xr;
    sz[xr] += sz[yr];
  } else {
    par[xr] = yr;
    sz[yr] += sz[xr];
  }
}

// MST algo
ll kruskal() {
  ll ans = 0;
  sort(edges.begin(), edges.end());
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    ll val = edges[i].first;
    if (find(u) != find(v)) {
      ans += val;
      merge(u, v);
    }
  }
  return ans;
}
