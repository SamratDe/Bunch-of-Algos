#include <vector>
using namespace std;

#define ll long long

vector<vector<int> > edges;

// SP between all pairs
void floydWarshall(int n) {
  vector<vector<ll> > dist(n + 1, vector<ll>(n + 1, 1e16+5));
  for (int i = 0; i < edges.size(); i++) {
    dist[edges[i][0]][edges[i][1]] = 1;
    dist[edges[i][1]][edges[i][0]] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}
