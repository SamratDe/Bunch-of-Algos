void bellman_ford(int n)
{	ll dist[n+1]={INT_MAX};
	rep(i,0,n-1)
	{	rep(j,0,graph.size())						// graph-> vec(pi( pi(int,int),int ) )
		{	int u=graph[j].first.first,v=graph[j].first.second;
			int wt=graph[j].second;
			if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
				dist[v]=dist[u]+wt;
		}
	}
}
