# include <vector>
using namespace std;
#define LL long long
#define INF8 1e16

const int N = 10001;
vector<int> graph[N];
vector<bool> vis(N, false), nodes(N, false);
vector<LL> discovery(N, 0), earliest(N, INF8), par(N, -1);

LL timeDisc = 0;

// using concept of backedge
void articulationPoints(int src) {
  vis[src] = 1;
  discovery[src] = earliest[src] = timeDisc + 1;
  timeDisc++;
  int num = 0;
  for (int i = 0; i < graph[src].size(); i++) {
    int v = graph[src][i];
    if (!vis[v]) {
      num++;
      par[v] = src;
      articulationPoints(v);
      // check if subtree rooted at v has backedge to ancestor of src
      earliest[src] = min(earliest[src], earliest[v]);
      // if src is root
      if (par[src] == -1 && num > 1) nodes[src] = true;
      // earliest time of any of it child is > discovery time of src i.e v has no backedge
      if (par[src] != -1 && earliest[v] >= discovery[src]) nodes[src] = true;
    } else if (v != par[src]) {
      // update the earliest value of u
      earliest[src] = min(earliest[src], discovery[v]);
    }
  }
}
