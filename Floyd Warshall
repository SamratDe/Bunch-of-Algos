void floyd_warshall(int n)
{	ll dist[n+1][n+1];
	rep(i,1,n+1)
		rep(j,1,n+1)
			dist[i][j]=graph[i][j];		// graph -> adjacency matrix
	rep(k,1,n+1)
		rep(i,1,n+1)
			rep(j,1,n+1)
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
}
