// const int M=100005;
// string pat,txt;
int lps[M];

void preprocess(){
	lps[0]=0;
	int i=1,len=0;
	while(i<pat.size()){
		if(pat[i]==pat[len]){
			len++;
			lps[i++]=len;
		}
		else{
			if(len!=0)
				len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void KMP(){
	preprocess();
	int i,j,cnt;
	i=j=cnt=0;
	while(i<txt.size()){
		if(txt[i]==pat[j])
			i++,j++;
		if(j==pat.size()){
			cnt++;
			j=lps[j-1];
		}
		else if(i<txt.size() && pat[j]!=txt[i]){
			if(j)
				j=lps[j-1];
			else
				i++;
		}
	}
	cout<<cnt<<endl;
}

//KMP();