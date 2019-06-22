//	Add vertex to the growing spanning tree

ll prims(int src)				// v -> vec(pi(ll,ll))
{	min_heap(pi(ll,ll)) q;
	ll mincost=0;
	pi(ll,ll) p;
	q.push({0,src});
	while(!q.empty())
	{	p=q.front();
		q.pop();
		ll x=p.second;
		if(vis[x])
			continue;
		mincost+=p.first;
		vis[x]=1;
		rep(i,0,v[x].size())
			if(!vis[v[x][i].second])
			{	q.push(v[x][i]);
				vis[v[x][i].second]=1;
			}
	}
	return mincost;
}
