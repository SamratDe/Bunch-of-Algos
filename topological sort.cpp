void topo(int v,bool *vis,stack<ll> &s){
	vis[v]=1;
	rep(i,0,graph[v].size())
		if(!vis[graph[v][i]])
			topo(graph[v][i],vis,s);
	s.push(v);
}

void topological_sort(int n){
	stack<ll> s;
	bool vis[n+1];
	mem(vis,false);
	rep(i,0,n)
		if(!vis[i])
			topo(i,vis,s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	//cout<<endl;
}
