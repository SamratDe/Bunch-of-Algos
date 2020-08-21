// find the shortest paths between between all pairs of vertices in a graph, 
// where each edge in the graph has a weight which is positive or negative

void floydWarshall(int n) {
	int dist[n + 1][n + 1] = {INT_MAX};

	// ADD THIS STEP !!!
	// make dist[i][j] = 1 if there is an edge between i & j
	
	// O(V^3)
	for (int k = 1; k <=n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
