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
