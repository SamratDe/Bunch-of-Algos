void precomp_kmp(string pat,int m,ll* lps)
{	ll len=0;
	lps[0]=0;  
    ll i=1; 
    while(i<m)
	{	if(parent[i]==parent[len])
		{ 	len++; 
            lps[i]=len; 
            i++; 
        } 
        else
        {	if(len!=0)
				len=lps[len-1]; 
            else
            { 	lps[i]=0; 
                i++; 
            } 
        } 
    } 
} 
  
// Prints occurrences of txt[] in pat[] 
void kmp(string parent,string txt) 
{	ll m=parent.size(),n=txt.size(); 
    ll lps[m];  
    precomp_kmp(parent,m,lps); 
    ll i=0,j=0; 
    while(i<n)
	{	if(parent[j]==txt[i])
		{	j++;i++;}
        if(j==m)
		{	count++; 
            j=lps[j-1]; 
        } 
        else if(i<n && parent[j]!=txt[i])
		{	if(j!=0) 
                j=lps[j-1]; 
            else
                i++; 
        } 
    } 
} 
 
