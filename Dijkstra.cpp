// finds the shortest paths from the source vertex to all other vertices in the graph.

// LOGIC :
// compares according to vertices distances. (use min priority queue)

// Why doesn't work with -ve cycles ? 

vector <pair <int, int> > graph[N];
vector <int> dist(N, INT_MAX);
vector <bool> visited(N, false);

int dijkstra(int src) {
	priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
	q.push(make_pair(0, src));
	dist[src] = 0;
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (visited[u]) {
			continue;
		}
		visited[u] = 1;
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].second;
			int wt = graph[u][i].first;
    		if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

// complexity: O(V + ElogV)

