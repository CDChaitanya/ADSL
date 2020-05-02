#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
	string keyword,meaning;
	node *lc,*rc;
public:
	node(string k,string m)
{
	keyword=k;
	meaning=m;
	lc=rc=NULL;
}
	friend class BST;
};

class BST
{
public:
	node *root;
	BST()
	{
		root=NULL;
	}
	void create(string k,string m)
	{
		if(root==NULL)
		{
			root=new node(k,m);
		}
		else
		{
			root=insert(root,k,m);
		}
	}
	node* insert(node *T,string k,string m)
	{
		if(T==NULL)
		{
			T=new node(k,m);
			return T;
		}
		else
		{
			int i;
			i=k.compare(T->keyword);
			if(i<0)
			{
				T->lc=insert(T->lc,k,m);
			}
			else if(i>0)
			{
				T->rc=insert(T->rc,k,m);
			}
			else if(i==0)
			{
				cout<<"\nThe word is already present";
			}
			return T;
		}
	}
	void inorder(node* t)
	{
		if(t == NULL)
		{
			return ;
		}
		else
		{
			inorder(t->lc);
			cout<<t->keyword <<" : "<<t->meaning <<endl;
			inorder(t->rc);
		}

	}
	void Mirror(node *t)
	{
		if(t== NULL)
			return;
		else
		{
			node *temp;
			Mirror(t->lc);
			Mirror(t->rc);

			temp=t->lc;
			t->lc=t->rc;
			t->rc=temp;
		}
	}
	void copy(node* n1,node* n2)   // OVERLOAD IT COMPLETELY
	{
		if(n1->lc!=NULL)
		{
			n2->lc=n1->lc;
			copy(n1->lc,n2->lc);
		}
		if(n1->rc!=NULL)
		{
			n2->rc=n1->rc;
			copy(n1->rc,n2->rc);
		}
	}
	void operator= (BST T)
	{
	     root=new node(T.root->keyword,T.root->meaning);
	     copy(T.root,root);
	}
	void update(node *t,string key,string mean)
	{
		if(t==NULL)
			return;

		else if(t->keyword == key)
		{
			t->meaning=mean;
		}
		else
		{
			if(t->lc!=NULL)
				update(t->lc,key,mean);
			if(t->rc!=NULL)
			    update(t->rc,key,mean);
		}
	}
	node* getMinimum(node *t)
	{
		//t=t->right;
		while(t->lc!=NULL)
		{
			t=t->lc;
		}
		return t;
	}
	node* deleteN(node *t,string k)
	{
		if(t==NULL)
			return t;
		if(k < t->keyword)
			t->lc=deleteN(t->lc,k);
		else if(k > t->keyword)
			t->rc=deleteN(t->rc,k);
		else
		{
		    if (t->lc == NULL)
		        {
		            node *temp = t->rc;
		            if(t==root)
		            	root=temp;
		            delete t;
		            return temp;
		        }
		    else if (t->rc == NULL)
		        {
		            node *temp = t->lc;
		            if(t==root)
		            	root=temp;
		            delete t;
		            return temp;
		        }
	        node* temp = getMinimum(t->rc);
	        t->keyword = temp->keyword;
	        t->meaning=temp->meaning;
	        t->rc = deleteN(t->rc , temp->keyword);
		}
		return t;
	}
	int search(node* t,string k)
	{
		if(t==NULL)
			return 0;
		if(t->keyword==k)
			return 1;
		else
		{
			if(k < t->keyword)
				return 1 + search(t->lc,k);
			else     //  IT IS FOR  (k > t->keyword)
				return 1 + search(t->rc,k);
		}
	}
};

int main()
{
	BST b,b1;
	int ch;
	string x,y;
	do
	{
		cout<<"1. CREATE"<<endl;
		cout<<"2. INSERT"<<endl;
		cout<<"3. ASCENDING ORDER (INORDER)"<<endl;
		cout<<"4. COPY"<<endl;
		cout<<"5. DESCENDING ORDER (INORDER OF MIRROR)"<<endl;
		cout<<"6. MODIFIY"<<endl;
		cout<<"7. DELETE NODE"<<endl;
		cout<<"8. SEARCH NODE"<<endl;
		cout<<"9. EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			cout<<"ENTER KEYWORD AND MEANING "<<endl;
			cin>>x>>y;
			b.create(x,y);
			break;
		}
		case 2:
		{
			cout<<"ENTER KEYWORD AND MEANING "<<endl;
			cin>>x>>y;
			b.insert(b.root,x,y);
			break;
		}
		case 3:
		{
			cout<<"THE ASCENDING ORDER IS "<<endl;
			b.inorder(b.root);
			break;
		}
		case 4:
		{
			b1=b;
			cout<<"THE COPIED TREE IS"<<endl;
			b1.inorder(b1.root);
			break;
		}
		case 5:
		{
			cout<<"THE DESCENDING ORDER IS "<<endl;
			b1.Mirror(b1.root);
			b1.inorder(b1.root);
			break;
		}
		case 6:                       // DIFFERENT METHOD IS ALSO PREFREABLE
		{
			string key,mean;
			cout<<"ENTER THE KEY WORD WHOSE MEANING YOU WANT TO CHANGE"<<endl;
			cin>>key;
			cout<<"ENTER MEANING"<<endl;
			cin>>mean;
			//b.update(b.root,key,mean);
			b.deleteN(b.root,key);
			b.inorder(b.root);
			b.insert(b.root,key,mean);
			cout<<"AFTER INSERTION OF NODE"<<endl;
			b.inorder(b.root);
			break;
		}
		case 7:
		{
			string key;
			cout<<"ENTER THE KEYWORD TO BE DELETED"<<endl;
			cin>>key;
			b.deleteN(b.root,key);
			break;
		}
		case 8:
		{
			string key;
			int cnt;
			cout<<"ENTER THE KEYWORD YOU WANT TO SEARCH"<<endl;
			cin>>key;
			cnt=b.search(b.root,key);
			cout<<"ELEMENT FOUND & COMPARISION ARE "<<cnt<<endl;
			break;
		}
		case 9:
		{
			exit(1);
			break;
		}
		default:
			cout<<"INVALID INPUT "<<endl;
		}
	}while(1);
}

