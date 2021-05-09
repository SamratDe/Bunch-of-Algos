# include <vector>
# include <iostream>
using namespace std;
#define LL long long
#define INF8 1e16

const int N = 10001;
vector<int> graph[N];
vector<bool> vis(N, false);
vector<LL> discovery(N, 0), earliest(N, INF8), par(N, -1);

LL timeDisc = 0;

// using concept of backedge
void findBridges(int src) {
  vis[src] = true;
  discovery[src] = earliest[src] = timeDisc + 1;
  timeDisc++;
  for (int i = 0; i < graph[src].size(); i++) {
    int v = graph[src][i];
    if (!vis[v]) {
      par[v] = src;
      findBridges(v);
      earliest[src] = min(earliest[src], earliest[v]);
      if (earliest[v] > discovery[src]) {
        cout << src << " " << v << endl;
      }
    }
    else if(v != par[src]) {
      earliest[src] = min(earliest[src], discovery[v]);
    }
  }
}
