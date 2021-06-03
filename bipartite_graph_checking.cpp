#include <vector>
using namespace std;

const int N = 100001;
vector<int> color(N, 0);
vector<int> graph[N];
vector<bool> vis(N, false);

// using 2 colors dfs code
// make vis[0] = true, before calling this function
bool checkForBipartite(int u) {
  for (int v : graph[u]) {
    if (!vis[v]) {
      vis[v] = true;
      color[v] = !color[u];
      if (!checkForBipartite(v)) return false;
    } else if (color[v] == color[u]) {
      return false;
    }
  }
  return true;
}
