vec(ll) dist(n+1,INF);	// n ??

void shortest_path(int src)
{	min_heap(pi(int,int) ) pq;
	pq.push({0,src});
	dist[src]=0;
	while(!pq.empty())
	{	ll u=pq.top().second;
		pq.pop();
		for(auto i:graph[u])		// graph[][] -> vec(pi(int,int)) 1st->node 2nd->wt
		{	ll v=i.first,wt=i.second; 
    		if(dist[v]>dist[u]+wt) 
    		{	dist[v]=dist[u]+wt; 
        		pq.push({dist[v],v}); 
    		} 
		}
	}
}
