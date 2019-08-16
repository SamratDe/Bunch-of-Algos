void update(ll *BITree,int n,int indx,ll val){
	indx++;
	while(indx<=n){
		BITree[indx]+=val;
		indx+=indx&(-indx);
	}
}

ll getSum(ll *BITree,int indx){
	ll sum=0;
	indx++;
	while(indx>0){
		sum+=BITree[indx];
		indx-=indx&(-indx);
	}
	return sum;
}

ll sum(int x,ll *BITree1,ll *BITree2){
	return getSum(BITree1,x)*x-getSum(BITree2,x);
}

void updateRange(ll *BITree1,ll *BITree2,int n,ll val,int l,int r){
	update(BITree1,n,l,val); 
    update(BITree1,n,r+1,-val); 
    update(BITree2,n,l,val*(l-1)); 
    update(BITree2,n,r+1,-val*r); 
}

ll rangeSum(int l,int r,ll *BITree1,ll *BITree2){
	return sum(r,BITree1,BITree2)-sum(l-1,BITree1,BITree2);
}
