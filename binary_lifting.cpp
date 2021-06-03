# include <vector>
using namespace std;

const int N = 200000;
const int M = 18;

// contain nodes from (0 to N-1)
vector<int> graph[N];
vector<int> depth(N, 0);
vector<bool> vis(N, false);
int dp[N][M];

// binary lifting
void dfs(int u) {
  vis[u] = true;
  for (int v : graph[u]) {
    if (vis[v]) continue;
    depth[v] = depth[u] + 1;
    dp[v][0] = u;
    for (int i = 1; i < M; i++) {
      dp[v][i] = dp[dp[v][i - 1]][i - 1];
    }
    dfs(v);
  }
}
