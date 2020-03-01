int par[N],sz[N];

void init(){
	rep(i,0,N){
		par[i]=i;
		sz[i]=1;
	}
}

int find(int x){
	if(par[x]!=x)
		par[x]=find(par[x]);
	return par[x];
}

void merge(int x,int y){
	int xr=find(x),yr=find(y);
	if(xr==yr)
		return;
	if(sz[xr]>=sz[yr]){
		par[yr]=xr;
		sz[xr]+=sz[yr];
	}
	else{
		par[xr]=yr;
		sz[yr]+=sz[xr];
	}
}
