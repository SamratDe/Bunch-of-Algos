void SieveOfEratosthenes(ll n) 
{   bool prime[n+1]; 
    mem(prime,true); 
    for(ll p=2;p*p<=n;p++) 
        if(prime[p]==true) 
            for(int i=p*p;i<=n;i+=p) 
                prime[i]=false; 
    for(ll p=2;p<=n;p++) 
        if(prime[p]) 
            //cout<<p<<" "; 
} 
