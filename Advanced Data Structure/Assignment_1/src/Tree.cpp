//============================================================================
// Name        : Tree.cpp
// Author      : 21418
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node
{
	int data;
	node *lc,*rc;
public:
	node(int x)
{
		data=x;
		lc=rc=NULL;
}
	friend class stack;
	friend class tree;
};

class stack
{
	int top;
	node *a[20];
public:
	stack()
{
		top=-1;
}
	int isempty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
	void push(node* x)
	{
		if(top==19)
			cout<<"LIST IS FULL"<<endl;
		else
		{
			a[++top]=x;
		}
	}
	node* pop()
	{
		node *x;
		if (top==-1)
		{
			return NULL;
		}
		else
		{
			x=a[top];
			top=top-1;
			//cout<<"top"<<top<<endl;
		}
		return x;
	}
};

class tree
{
	node *root;
public:
	tree()
{
		root =NULL;
}
	tree(node *t)
{
		root =t;
}
	void create(int x)
	{
		if(root==NULL)
			root=new node(x);
		else
		{
			cout<<"TREE IS ALREADY CREATED"<<endl;
			root=insert(x,root);
		}
	}
	node* insert(int x,node *rut)
	{
		if(rut==NULL)
		{
			rut=new node(x);
			return rut;
		}
		else
		{
			int ch;
			cout<<"LEFT(0) OR RIGHT(1)"<<endl;
			cin>>ch;
			if(ch)
				rut->rc=insert(x,rut->rc);
			else
				rut->lc= insert(x,rut->lc);
			return rut;
		}
	}
	node* ret_root()
	{
		return root;
	}
	void inorder(node *t)
	{
		if(t==NULL)
		{
			return;
		}
		else
		{
			inorder(t->lc);
			cout<<t->data<<endl;
			inorder(t->rc);
		}
	}
	void preorder(node *t)
	{
		if(t==NULL)
		{
			return;
		}
		else
		{
			cout<<t->data<<endl;
			preorder(t->lc);
			preorder(t->rc);
		}
	}
	void postorder(node *t)
	{
		if(t==NULL)
		{
			return;
		}
		else
		{
			postorder(t->lc);
			postorder(t->rc);
			cout<<t->data<<endl;
		}
	}

	void non_rec_inorder(node *t)
	{
		stack st;
		while(t!=NULL || !st.isempty())
		{
			if(t!=NULL)
			{
				st.push(t);
				t=t->lc;
			}
			else
			{
				t=st.pop();
				cout<<t->data<<endl;
				t=t->rc;
			}
		}
	}
	void non_rec_preorder(node *t)
	{
		stack st;
		while(t!=NULL || !st.isempty())
		{
			if(t!=NULL)
			{
				cout<<t->data<<endl;
				st.push(t);
				t=t->lc;
			}
			else
			{
				t=st.pop();
				t=t->rc;
			}
		}

	}
	void non_rec_postorder(node *t)    // PROBLEM
	{
		if(t==NULL)
			return;
		stack s1,s2;
		s1.push(t);
		node *temp;
		while(!s1.isempty())
		{
			temp=s1.pop();
			s2.push(temp);
			if(temp->lc)
				s1.push(temp->lc);
			if(temp->rc)
				s1.push(temp->rc);
		}
		while(!s2.isempty())
		{
			temp=s2.pop();
			cout<<temp->data<<endl;
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
	void erase(node *t)
	{
		if(t==NULL)
		{
			return;
		}
		else if(t->lc==NULL && t->rc==NULL)
		{
			delete t;
			return;
		}
		else
		{
			erase(t->lc);
			erase(t->rc);
		}
	}
	int leaf(node *t)
	{
		int l,r;
		if(t==NULL)
		{
			return 0;
		}
		if(t->lc==NULL && t->rc==NULL)
		{
			cout<<t->data<<endl;
			return 1;
		}
		else
		{
			l=leaf(t->lc);
			r=leaf(t->rc);
			return l+r;
		}
	}
	int internal(node *t)
	{
		int l,r;
		if(t==NULL)
		{
			return 0;
		}
		if((t->lc!=NULL || t->rc!=NULL)  && t!=root)
		{
			cout<<t->data<<endl;
			return 1;
		}
		else
		{
			l=leaf(t->lc);
			r=leaf(t->rc);
			return l+r;
		}
	}
	void copy(node* n1,node* n2)
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
	void operator= (tree T)
	{
		root=new node(T.root->data);
		copy(T.root,root);
	}

	int isequal(node* n1,node* n2)
	{
		if(n1==NULL && n2==NULL)
			return 1;
		else if(n1!=NULL && n2!=NULL)
		{
			return{
				n1->data==n2->data &&  isequal(n1->lc,n2->lc)  &&  isequal(n1->rc,n2->rc)
			};
		}
		else
			return 0;
	}
};

int main()
{
	tree t,q,c,neww;
	int ch,x,n;
	node *p;
	node *m;
	do
	{
		cout<<"1. CREATE"<<endl;
		cout<<"2. INSERT"<<endl;
		cout<<"3. INORDER"<<endl;
		cout<<"4. PREORDER"<<endl;
		cout<<"5. POSTORDER"<<endl;
		cout<<"6. NON_RECURSIVE INORDER "<<endl;
		cout<<"7. NON_RECURSIVE PREORDER "<<endl;
		cout<<"8. NON_RECURSIVE POSTORDER "<<endl;
		cout<<"9. ERASE"<<endl;
		cout<<"10.MIRROR IMAGE "<<endl;
		cout<<"11.LEAF NODES"<<endl;
		cout<<"12.INTERNAL NODES"<<endl;
		cout<<"13.COPY"<<endl;
		cout<<"14.CREATE NEW TREE "<<endl;
		cout<<"15.INSERT IN NEW TREE "<<endl;
		cout<<"16.IS EQUAL"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			cout<<"ENTER VALUE TO BE ADDED "<<endl;
			cin>>x;
			t.create(x);
			break;
		}
		case 2:
		{
			cout<<"ENTER VALUE TO BE ADDED "<<endl;
			cin>>x;
			p=t.ret_root();
			t.insert(x,p);
			break;
		}
		case 3:
		{
			cout<<"THE INORDER IS "<<endl;
			node *p=t.ret_root();
			t.inorder(p);
			break;
		}
		case 4:
		{
			cout<<"THE PREORDER IS "<<endl;
			node *p=t.ret_root();
			t.preorder(p);
			break;
		}
		case 5:
		{
			cout<<"THE POSTORDER IS "<<endl;
			node *p=t.ret_root();
			t.inorder(p);
			break;
		}
		case 6:
		{
			cout<<"THE NON_RECURSIVE INORDER IS "<<endl;
			node *p=t.ret_root();
			t.non_rec_inorder(p);
			break;
		}
		case 7:
		{
			cout<<"THE NON_RECURSIVE PREORDER IS "<<endl;
			node *p=t.ret_root();
			t.non_rec_preorder(p);
			break;
		}
		case 8:
		{
			cout<<"THE NON_RECURSIVE POSTORDER IS "<<endl;
			node *p=t.ret_root();
			t.non_rec_postorder(p);
			break;
		}
		case 9:
		{
			node *p=t.ret_root();
			t.erase(p);
			break;
		}
		case 10:
		{
			node *p=t.ret_root();
			t.Mirror(p);
			break;
		}
		case 11:
		{
			int cnt;
			node *p=t.ret_root();
			cnt=t.leaf(p);
			cout<<"THE TOTAL NUMBER OF LEAF NODES ARE "<<cnt<<endl;
			break;
		}
		case 12:
		{
			int cnt;
			node *p=t.ret_root();
			cnt=t.internal(p);
			cout<<"THE TOTAL NUMBER OF INTERNAL NODES ARE "<<cnt<<endl;
			break;
		}
		case 13:
		{
			tree t1;
			t1=t;
			p=t1.ret_root();
			cout<<"THE COPIED TREE IS"<<endl;
			t1.inorder(p);
			break;
		}
		case 14:
		{
			cout<<"ENTER VALUE TO BE ADDED "<<endl;
			cin>>x;
			neww.create(x);
			break;
		}
		case 15:
		{
			cout<<"ENTER VALUE TO BE ADDED "<<endl;
			cin>>x;
			p=neww.ret_root();
			neww.insert(x,p);
			break;
		}
		case 16:
		{
			p=t.ret_root();
			m=neww.ret_root();
			if(t.isequal(p,m))
				cout<<"TREES ARE EQUAL"<<endl;
			else
				cout<<"TREES ARE NOT EQUAL"<<endl;
			break;
		}

		default:
			cout<<"INVALID INPUT "<<endl;
		}
	}while(1);
}
