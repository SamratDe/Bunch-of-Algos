# include <vector>
# include <stack>
using namespace std;

const int N = 100001;
vector<int> graph[N];
vector<bool> vis(N, false);
stack<int> topoOrder;

void topoSort(int src){
  vis[src] = true;
  for (int i = 0; i < graph[src].size(); i++) {
    int v = graph[src][i];
    if (!vis[v]) {
      topoSort(v);
    }
  }
  topoOrder.push(src);
}
