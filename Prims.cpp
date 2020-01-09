//	Add vertex to the growing spanning tree

int prims(int src){				// v -> vec(pi(dist,node))
	min_heap(pi(int,int)) q;
	int minCost=0;
	pi(int,int) p;
	q.push({0,src});
	while(!q.empty()){
		p=q.top();
		q.pop();
		int x=p.second;
		if(vis[x])
			continue;
		minCost+=p.first;
		vis[x]=1;
		rep(i,0,v[x].size())
			if(!vis[v[x][i].second])
				q.push(v[x][i]);
	}
	return minCost;
}
