// graph structure -> vector<pair<int, int>> graph[N]

int dist[N] = {INT_MAX};

void 0_1bfs(int src) {
	deque <int> q;
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
				if (wt == 0) {
					q.push_front(v);
				} else {
					q.push_back(v);
				}
			}
		}
	}
}
