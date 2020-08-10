// BFS code

// LOGIC :
// First move horizontally and visit all the nodes of the current layer
// Move to the next layer

void bfs(int src, int nodeSize) {
	queue <int>  q;
	vector <bool> visited(nodeSize + 1, false);

	q.push(src);
	visited[src] = true;

	while (!q.empty()) {
		int u = q.front();
		// cout << "Node : "<< u << " ";
		q.pop();
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (visited[v] == false) {
				q.push(v);
				visited[v] = true;
			}
		}
	}

	// cout << endl;
}
