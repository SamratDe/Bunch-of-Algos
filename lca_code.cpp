# include <vector>
using namespace std;

const int N = 100001;
const int H = 14;

vector<int> child[N];
int dp[N][H];
int depth[N];

void dfs(int u) {
  for (int v : child[u]) {
    dp[v][0] = u;
    depth[v] = depth[u] + 1;
    for (int j = 1; j < H; j++) {
      dp[v][j] = dp[dp[v][j - 1]][j - 1];
    }
    dfs(v);
  }
}

int getLca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  // go up the diff
  int diff = depth[u] - depth[v];
  for (int j = N - 1; j >= 0; j--) {
    if (diff & (1 << j)) {
      u = dp[u][j];
    }
  }
  if (u == v) return u;
  for (int j = H - 1; j >= 0; j--) {
    if (dp[u][j] != dp[v][j]) {
      u = dp[u][j];
      v = dp[v][j];
    }
  }
  return dp[u][0];
}