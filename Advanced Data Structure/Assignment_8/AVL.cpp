#include <iostream>
#include <string>
using namespace std;

class node
{
    node *lc,*rc;
    string key,mean;
    int height;
    public:
    node(string k,string m)
    {
        key=k;
        mean=m;
    }
    friend class avl;
};
class avl
{
    public:
    node* root;
    avl()
    {
        root=NULL;
    }
    int node_height(node *p)
    {
        int hl=0,hr=0;
        hl= p && p->lc ? p->lc->height:0;
        hr= p && p->rc ? p->rc->height:0;

        return(hl > hr ? hl+1:hr+1);
    }
    int BF(node*p)
    {
        int hl,hr;
        hl= p && p->lc ? p->lc->height:0;
        hr= p && p->rc ? p->rc->height:0;

        return(hl - hr);
    }  
    node *LL(node* p)
    {
        node *pl  = p->lc;
        node *plr = pl->rc;

        pl->rc=p;
        p->lc=plr;

        p->height=node_height(p);
        pl->height=node_height(pl);

        if(root == p)
            root=pl;

        return pl;
    }
    node *LR(node* p)
    {
        node *pl  = p->lc;
        node *plr = pl->rc;

        pl->rc=plr->lc;
        p->lc=plr->rc;

        plr->lc=pl;
        plr->rc=p;

        p->height=node_height(p);
        pl->height=node_height(pl);
        plr->height=node_height(plr);

        if(root == p)
            root=plr;

        return plr;
    }
    node *RR(node* p)
    {
        node *pr  = p->rc;
        node *prl = pr->lc;

        pr->lc=p;
        p->rc=prl;

        p->height=node_height(p);
        pr->height=node_height(pr);

        if(root == p)
            root=pr;

        return pr;
    }
    node *RL(node* p)
    {
        node *pr  = p->rc;
        node *prl = pr->lc;

        pr->lc=prl->rc;
        p->rc=prl->lc;

        prl->lc=p;
        prl->rc=pr;

        p->height=node_height(p);
        pr->height=node_height(pr);
        prl->height=node_height(prl);

        if(root == p)
            root=prl;

        return prl;
    }
    node* insert(node*p,string k,string m)
    {
        node*t=NULL;
        if(p==NULL)
        {
            t=new node(k,m);
            t->height=0;                          
            return t;
        }
        if(k < p->key)
            p->lc=insert(p->lc,k,m);
        else if(k > p->key)
            p->rc=insert(p->rc,k,m);
        
        p->height=node_height(p);

        if(BF(p) == 2 && BF(p->lc)==1)
            return LL(p);
        else if(BF(p) == 2 && BF(p->lc)==-1)
            return LR(p);
        else if(BF(p) == -2 && BF(p->rc)==-1)
            return RR(p);
        else if(BF(p) == -2 && BF(p->rc)==1)
            return RL(p);

        return p;
    }
	void inorder(node* t)
	{
		if(t != NULL)
		{
			inorder(t->lc);
			cout<<t->key <<" : "<<t->mean <<endl;
			inorder(t->rc);
		}
	}
};
int main()
{
    avl a;
    int ch;
    string x,y;
    do
    {
        cout<<"1. INSERT"<<endl;
        cout<<"2. ASCENDING ORDER (INORDER)"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"ENTER KEYWORD AND MEANING "<<endl;
                cin>>x>>y;
                a.root=a.insert(a.root,x,y);
                break;
            }
            case 2:
            {
                cout<<"INORDER(ASCENDING ORDER)"<<endl;
                a.inorder(a.root);
                break;
            }
            case 3:
            {
                exit(1);
                break;
            }
            default:
                cout<<"INVALID INPUT "<<endl;
        }
    }while(1);
} 
/*#include <iostream>
#include <string>
using namespace std;

class node
{
    node *lc,*rc;
    string key,mean;
    int height;
    public:
    node(string k,string m)
    {
        key=k;
        mean=m;
    }
    friend class avl;
};
class avl
{
    public:
    node* root;
    avl()
    {
        root=NULL;
    }
    int node_height(node *p)
    {
        int hl=0,hr=0;
        hl= p && p->lc ? p->lc->height:0;
        hr= p && p->rc ? p->rc->height:0;

        return(hl > hr ? hl+1:hr+1);
    }
    int BF(node*p)
    {
        int hl,hr;
        hl= p && p->lc ? p->lc->height:0;
        hr= p && p->rc ? p->rc->height:0;

        return(hl - hr);
    }  
    node *LL(node* p)
    {
        node *pl  = p->lc;
        //node *plr = pl->rc;
        p->lc=pl->rc;
        pl->rc=p;
        p->height=node_height(p);
        pl->height=node_height(pl);
        if(root == p)
            root=pl;
        return pl;
    }
    node *LR(node* p)
    {
        node *pl  = p->lc;
        node *plr = pl->rc;

        pl->rc=plr->lc;
        p->lc=plr->rc;

        plr->lc=pl;
        plr->rc=p;

        p->height=node_height(p);
        pl->height=node_height(pl);
        plr->height=node_height(plr);

        if(root == p)
            root=plr;
       if (root->rc ==p)
	root->rc = plr;

        return root;
    }
    node *RR(node* p)
    {
        node *pr  = p->rc;
        node *prl = pr->lc;

        pr->lc=p;
        p->rc=prl;

        p->height=node_height(p);
        pr->height=node_height(pr);

        if(root == p)
            root=pr;
        return pr;
    }
    node *RL(node* p)
    {
        node *pr  = p->rc;
       // node *prl = pr->rc;
        node *prl = pr->lc;

        pr->lc=prl->rc;
        p->rc=prl->lc;

        prl->lc=p;
        prl->rc=pr;

        p->height=node_height(p);
        pr->height=node_height(pr);
        prl->height=node_height(prl);

        if(root == p)
            root=prl;
        if (root->lc ==p)
	root->lc = prl;
        return root;
    }
    node* insert(node*p,string k,string m)
    {
        node*t=NULL;
        if(p==NULL)
        {
            t=new node(k,m);
            t->height=1;                          
            return t;
        }
        if(k < p->key)
            p->lc=insert(p->lc,k,m);
        else if(k > p->key)
            p->rc=insert(p->rc,k,m);
        
        p->height=node_height(p);

        if(BF(p) == 2 && BF(p->lc)==1)
            return LL(p);
        else if(BF(p) == 2 && BF(p->lc)==-1)
            return LR(p);
        else if(BF(p) == -2 && BF(p->rc)==-1)
            return RR(p);
        else if(BF(p) == -2 && BF(p->rc)==1)
            return RL(p);
        return p;
    }
	void inorder(node* t)
	{
		if(t != NULL)
		{
			inorder(t->lc);
			cout<<t->key <<" : "<<t->mean <<endl;
			inorder(t->rc);
		}
	}
};
int main()
{
    avl a;
    int ch;
    string x,y;
    do
    {
        cout<<"1. INSERT"<<endl;
        cout<<"2. ASCENDING ORDER (INORDER)"<<endl;
        cout<<"3. EXIT"<<endl;
        cout<<"ENTER YOUR CHOICE"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                cout<<"ENTER KEYWORD AND MEANING "<<endl;
                cin>>x>>y;
                a.root = a.insert(a.root,x,y);
                break;
            }
            case 2:
            {
                cout<<"INORDER(ASCENDING ORDER)"<<endl;
                a.inorder(a.root);
                break;
            }
            case 3:
            {
                exit(1);
                break;
            }
            default:
                cout<<"INVALID INPUT "<<endl;
        }
    }while(1);
}*/