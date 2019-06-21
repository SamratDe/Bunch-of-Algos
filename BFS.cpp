void bfs(int src)
{	queue<int> q;
	q.push(src);
	vis[src]=1;
	while(!q.empty())
	{	int p=q.front();
		q.pop();
		rep(i,0,v[p].size())
		{	if(!vis[v[p][i]])
			{	q.push(v[p][i]);
				vis[v[p][i]]=1;
			}
		}
	}
}
