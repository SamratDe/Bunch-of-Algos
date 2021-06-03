# include <vector>
# include <queue>
using namespace std;
#define ll long long

const int N = 100001;
vector<pair<int, int> > graph[N];
vector<ll> dist(N, 1e61 + 5);

// SP from src to all other vertices when edges are of weight 0 & 1
void bfs(int src) {
	deque<int> q;
	q.push_back(src);
	dist[src] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int wt = graph[u][i].second;
			if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				if (wt == 0) q.push_front(v);
        		else q.push_back(v);
			}
		}
	}
}
