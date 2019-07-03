// inorder using stack s

while(1)
{	while(ptr->left!=NULL)
	{	s.push(ptr);
		ptr=ptr->left;
	}
	while(ptr->right==NULL)
	{	cout<<ptr->val<<" ";
		if(s.empty())
			return;
		ptr=s.top();
		s.pop();
	}
	cout<<ptr->val<<" ";
	ptr=ptr->right;
}

//postorder using stack s

q=ptr;
while(1)
{	while(ptr->left!=NULL)
	{	s.push(ptr);
		ptr=ptr->left;
	}
	while(ptr->right==NULL || ptr->right==q)
	{	cout<<ptr->val<<" ";
		q=ptr;
		if(s.empty())
			return;
		ptr=s.top();
		s.pop();
	}
	s.push(ptr);
	ptr=ptr->right;
}
