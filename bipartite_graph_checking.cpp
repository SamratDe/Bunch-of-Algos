#include <vector>
using namespace std;

const int N = 100001;
vector<int> color(N, 0);
vector<int> graph[N];
vector<bool> vis(N, false);

// using 2 colors dfs code
bool checkForBipartite(int src) {
  for(int i = 0; i < graph[src].size(); i++) {
    int v = graph[src][i];
    if (!vis[v]) {
      vis[v] = true;
      color[v] = !color[src];
      if (!checkForBipartite(v)) return false;
    } else if (color[v] == color[src]) {
      return false;
    }
  }
  return true;
}
