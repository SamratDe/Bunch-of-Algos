// v[][] -> graph

bool check(int src)
{	int color[....];
	rep(i,0,...)
		color[i]=-1;
	color[src]=1;
	queue<int> q; 
    q.push(src); 
    while(!q.empty())
    {	int u=q.front();
    	q.pop();
    	vis[u]=1;
    	rep(i,0,v[u].size())
    	{	if(color[v[u][i]]==-1)
    		{	color[v[u][i]]=1-color[u];
    			q.push(v[u][i]);
    		}
    		else if(color[v[u][i]]==color[u])
    			return false;
    	}
    }
    return true;
}
