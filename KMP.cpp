void precomp_kmp(string txt,int m,ll* lps)
{	ll len=0;
	lps[0]=0;  
    ll i=1; 
    while(i<m)
	{	if(txt[i]==txt[len])
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
  
// Prints occurrences of txt[] in parent[] 
ll kmp(string txt,string parent) 
{	ll m=txt.size(),n=parent.size(); 
    ll lps[m];  
    precomp_kmp(txt,m,lps); 
    ll i=0,j=0,count=0; 
    while(i<n)
	{	if(txt[j]==parent[i])
		{	j++;i++;}
        if(j==m)
		{	count++; 
            j=lps[j-1]; 
        } 
        else if(i<n && txt[j]!=parent[i])
		{	if(j!=0) 
                j=lps[j-1]; 
            else
                i++; 
        } 
    } 
    return count;
} 
