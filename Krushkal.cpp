int par[100005],rnk[100005];

void intialize(int n)
{	rep(i,0,n)
	{	par[i]=i;
		rnk[i]=1;
	}
}

int find(int x)
{	if(par[x]!=x)
		par[x]=find(par[x]);
	return par[x];
}

void merge(int x,int y)
{	int xr=find(x),yr=find(y);
	if(xr==yr)
		return;
	if(rnk[xr]>rnk[yr])
		par[yr]=xr;
	else if(rnk[yr]>rnk[xr])
		par[xr]=yr;
	else{
		par[yr]=xr;
		rnk[xr]+=1;
	}
}

//	Adding edges one by one to the growing spanning tree(greedy approach)
//	adds the edge which has least weight

ll krushkal(pi(ll,pi(ll,ll)) p[],int edges)	 	//p[] -> {wt, {vertex1, vertex2} } sorted by wt
{	ll cost,mincost=0;
	rep(i,0,edges) 
	{	ll x=p[i].second.first,y=p[i].second.second;
		cost=p[i].first;
		if(find(x)!=find(y))
		{	mincost+=cost;
			merge(x,y);
		}
	}
	return mincost;
}
