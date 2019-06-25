struct node
{   struct node *child[26];
    bool isEnd;
};

struct node *getNode()
{   struct node *p=new node;
    p->isEnd=0;
    for(int i=0;i<26;i++)
        p->child[i]=NULL;
    return p;
}

void insert(struct node *root,string s)
{   struct node *ptr=root;
    for(int i=0;i<s.size();i++)
    {   int indx=s[i]-'a';
        if(ptr->child[indx]==NULL)
            ptr->child[indx]=getNode();
        ptr=ptr->child[indx];
    }
    ptr->isEnd=1;
}

bool search(node *root,string s)
{   struct node *ptr=root;
    for(int i=0;i<s.size();i++)
    {   int indx=s[i]-'a';
        if(ptr->child[indx]==NULL)
            return 0;
        ptr=ptr->child[indx];
    }
    return (ptr!=NULL && ptr->isEnd);
}
