ll permute(int n,int k) 
{ 	ll fact[n + 1];
    fact[0]=1;  
    rep(i,1,n+1)
        fact[i]=i*fact[i-1]; 
    return fact[n]/fact[n-k]; 
} 
