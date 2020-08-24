// add vectors -> visited, graph

bool checkForBipartite(int src, vector <int> &color) {
	for (int i = 0; i < graph[src].size(); i++) {
		int v = graph[src][i];
		if (!visited[v]) {
			visited[v] = 1;
			color[v] = !color[src];
			if (!checkForBipartite(v, color)) {
				return false;
			}
		} else if (color[v] == color[src]) {
			return false;
		}
	}
	return true;
}
