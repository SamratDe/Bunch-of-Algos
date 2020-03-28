//vec(int) graph[N];
//vec(bool) vis(N,false);
vec(int) disc(N,0),low(N,0),par(N,-1);

void dfs1(int u){
	static int tt=0;
	vis[u]=1;
	disc[u]=low[u]=++tt;
	rep(i,0,graph[u].size()){
		int v=graph[u][i];
		if(!vis[v]){
			par[v]=u;
			dfs1(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>disc[u])
                cout<<u<<" "<<v<<endl;
		}
		else if(v!=par[u])
			low[u]=min(low[u],disc[v]);
	}
}

// rep(i,1,n+1)
//     dfs1(i);