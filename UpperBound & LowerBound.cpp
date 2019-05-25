// when the element is present
// returns 0-based index position

ll lowerbound(ll arr[],int n,ll key)
{	int ans=0,l=0,h=n-1;
	while(l<=h)
	{	if(arr[mid]==key)
		{	ans=mid;
			h=mid-1;
		}
		else if(arr[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return ans;
}

ll upperbound(ll arr[],int n,ll key)
{	int ans=0,l=0,h=n-1;
	while(l<=h)
	{	if(arr[mid]==key)
		{	ans=mid;
			l=mid+1;
		}
		else if(arr[mid]>key)
			h=mid-1;
		else
			l=mid+1;
	}
	return ans;
}
