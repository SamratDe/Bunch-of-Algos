//this should work!

const int N=100005;
int arr[N];

typedef struct node{
  int val;
  void leaf(int x){	
    val=x;
  }
  void merge(node x,node y){
    val=x.val+y.val;
  }
}node;

void build(node segment[],int low,int high,int num){
  if(low==high){
    segment[num].leaf(arr[low]);
    return;
  }
  int mid=(low+high)/2;
  build(segment,low,mid,2*num);
  build(segment,mid+1,high,2*num+1);
  segment[num].merge(segment[2*num],segment[2*num+1]);
}

void update(node segment[],int *lazy,int low,int high,int l,int r,int val,int num){
  if(lazy[num]){
    segment[num].val=(high-low+1)*lazy[num];
    if(high!=low){
      lazy[2*num]+=lazy[num];
      lazy[2*num+1]+=lazy[num];
    }
    lazy[num]=0;
  }
  if(low>high || low>r || high<l)
    return;
  if(l<=low && r>= high){
    segment[num].val+=(high-low+1)*val;
    if(low!=high){
      lazy[2*num]+=val;
      lazy[2*num+1]+=val;
    }
  }
  else{
    int mid=(low+high)/2;
    update(segment,lazy,low,mid,l,r,val,2*num);
    update(segment,lazy,mid+1,high,l,r,val,2*num+1);
    segment[num].merge(segment[2*num],segment[2*num+1]);
  }
}

node query(node segment[],int *lazy,int low,int high,int l,int r,int num){
  if(lazy[num]){
        segment[num].val=(high-low+1)*lazy[num];
        if(high!=low){
            lazy[2*num]+=lazy[num];
            lazy[2*num+1]+=lazy[num];
        }
        lazy[num]=0;
    }
    if(l<=low && r>= high)
    return segment[num];
  int mid=(low+high)/2;
  if(mid>=r)
    return query(segment,lazy,low,mid,l,r,2*num);
  else if(mid<l)
    return query(segment,lazy,mid+1,high,l,r,2*num+1);
  node m=query(segment,lazy,low,mid,l,r,2*num);
  node n=query(segment,lazy,mid+1,high,l,r,2*num+1);
  node p;
  p.merge(m,n);
  return p;
}