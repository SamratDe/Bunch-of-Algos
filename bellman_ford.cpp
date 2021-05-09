# include <vector>
# include <utility>
using namespace std;
#define ll long long

// LOGIC: 
// Shortest path contains at most (n - 1) edges, because the shortest path couldn't have a cycle.

// Bellman Ford algo can checks if there exists a negative cycle
// Negative cycle test done if outer loop runs 1 more time

// Complexity: O(V * E)

const int N = 10001;
vector<pair<int, pair<int, ll> > > edges;
vector<ll> dist(N, 1e16+5);

// SP from src to all vertices
void bellmanFord(int src, int n) {
  dist[src] = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int u = edges[j].first;
      int v = edges[j].second.first;
      ll val = edges[j].second.second;
      if (dist[v] > dist[u] + val) {
        dist[v] = dist[u] + val;
      }
    }
  }
}
