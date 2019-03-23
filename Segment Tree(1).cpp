int arr[ ];		//size?

typedef struct node
{	//variables
	
	void leaf(int x)
	{	
	
	}
	void merge(node x,node y)
	{
	
	}
}node;

void build(node segment[],int low,int high,int num)
{
	if(low==high)
	{	segment[num].leaf(arr[low]);
		return;
	}
	int mid=(low+high)/2;
	build(segment,low,mid,2*num);
	build(segment,mid+1,high,2*num+1);
	segment[num].merge(segment[2*num],segment[2*num+1]);
}

void update(node segment[],int low,int high,int indx,int val,int num)	//point update
{
	if(low==high)
	{	arr[indx]=val;
		segment[num].ele=val;
	}
	else
	{	int mid=(low+high)/2;
		if(indx>=low && indx<=mid)	
			update(segment,low,mid,indx,val,2*num);
		else
			update(segment,mid+1,high,indx,val,2*num+1);
		segment[num].merge(segment[2*num],segment[2*num+1]);
	}
}

node query(node segment[],int low,int high,int l,int r,ll num)			// range query
{
	if(l<=low && r>= high)
		return segment[num];
	int mid=(low+high)/2;
	if(mid>=r)
		return query(segment,low,mid,l,r,2*num);
	else if(mid<l)
		return query(segment,mid+1,high,l,r,2*num+1);
	node m=query(segment,low,mid,l,r,2*num);
	node n=query(segment,mid+1,high,l,r,2*num+1);
	node p;
	p.merge(m,n);
	return p;
}

// size of tree -> N=2*pow(2,ceil(log2(n)))      n is the size of arr[]



