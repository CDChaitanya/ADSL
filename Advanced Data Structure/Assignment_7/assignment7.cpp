#include <iostream>
#include<stdlib.h>
using namespace std;

class node
{
public:
	string key,val;
	int chain;
	node()
	{
		key="z";
		val="z";
		chain=-1;
	}
};
class dict
{
	node obj[26];

public:

	void create(int a)
	{

		string x,y;

			while(1)
			{
			cout<<"Enter key or -1 to stop"<<endl;
			cin>>x;

			if(x=="-1")
			break;
			cin.ignore(-1);
			cout<<"Enter value"<<endl;
			cin>>y;
			if(a==0)
			insert(x,y);
			else
				insert1(x,y);
			}


	}
	int index(string x)
	{
		char ch;
		int a,b;
		ch=x[0];
		a=ch-97;
		b=a;

		if(obj[a].key != "z")
		{

			while(obj[a].key != "z")
			{
				if(a==25)
					a=0;
				else
					a++;
			}
			if(a == b)
			{
				return -1;
			}
		}
		return a;
	}
	void insert(string x,string y)
	{
		int p;
		char ch=x[0];
		int a=ch-97;
		int b=index(x);
		int flag=0;
		if(obj[a].key == "z")
		{
			obj[a].key=x;
			obj[a].val=y;
		}
		else
		{
			if(obj[a].key[0] == x[0])
			{
				while(obj[a].chain != -1)
				{
					a=obj[a].chain;
				}
				obj[b].key=x;
				obj[b].val=y;
				obj[a].chain=b;
			}
			else
			{
				int ind=a;
				while(ind<b)
				{
					if(obj[ind].key[0]==x[0])
					{
						flag=1;
						break;

					}
					ind++;
				}
				if(!flag)
				{
					obj[b].key=x;
					obj[b].val=y;
				}
				else
				{
					while(obj[ind].chain!=-1)
					{
							ind=obj[ind].chain;
					}
					obj[b].key=x;
					obj[b].val=y;
					obj[ind].chain=b;
				}
			}
		}
	}
	void insert1(string x,string y)
	{
		int a=index(x);
		if(a==-1)
		{
			cout<<"can not insert"<<endl;
			return;
		}
		char ch=x[0];
		int c=ch-97;
		if(a != c)
		{
			if(obj[c].key[0] == x[0])
			{
				while(obj[c].chain != -1)
				{
					c=obj[c].chain;
				}
				obj[a].key=x;
				obj[a].val=y;
				obj[c].chain=a;
			}
			else
			{
				int p=0,q=0;
				while(obj[p].chain != c)
				{
					p++;
				}
				q=obj[c].chain;
				obj[a].key=obj[c].key;
				obj[a].val=obj[c].val;
				obj[a].chain=q;
				obj[p].chain=a;
				obj[c].key=x;
				obj[c].val=y;
				obj[c].chain=-1;
			}
		}
		else
		{
			obj[c].key=x;
			obj[c].val=y;
		}
	}
	void display()
	{
		string a,b;
		for(int i=0;i<26;i++)
		{
			if(obj[i].key=="z")
			{
				 a="  -  ";
				 b="  -  ";
			}
			else
			{
				 a=obj[i].key;
				 b=obj[i].val;
			}
			cout<<i<<" "<<a<<"  :   "<<b<<"  :   "<<obj[i].chain<<endl;
		}
	}
	void del(string x)
	{
		char ch;

		int c=0;

		while(obj[c].key != x)
		{
			c++;
		}
		int p=c;
		while(obj[c].chain != -1)
		{	
			obj[c].key=obj[obj[c].chain].key;
			obj[c].val=obj[obj[c].chain].val;
			p=c;
			c=obj[c].chain;
		}

		obj[c].key="z";
		obj[c].val="z";
		obj[p].chain=-1;
	}
	int search(string x)
	{
		int c=0;
		while(obj[c].key!=x && c<26)
		{
					c++;
		}
		if(c<26)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void ret(string x)
	{
		int c=0;
		while(obj[c].key!=x && c<26)
		{
			c++;
				}
				if(c<26)
				{
					cout<<obj[c].val<<endl;
				}
				else
				{
					cout<<"not present"<<endl;
				}

	}
	void modify(string x)
	{
		int c=0;
		string y;
		while(obj[c].key!=x && c<26)
		{
			c++;
		}
		if(c<26)
		{
			cout<<"Enter attribute"<<endl;
			cin>>y;
			obj[c].val=y;
		}
		else
		{
			cout<<"not present"<<endl;
		}
	}
};

int main()
{0
	dict obj;
	string x,y;
	int a,b;
	cout<<"1.without replacement\n2.with replacement"<<endl;
	cin>>b;
	if(b==1)
	{
	obj.create(0);
	obj.display();
	while(1)
	{
		cout<<"Enter 1.search name\n 2.retrive attributes\n 3. modify attributes \n 4.Insert entry\n 5.Delete Entery\n 6.Exit"<<endl;
		cin>>a;
		switch(a)
		{
		case 1:
		{
			cout<<"Enter name to search"<<endl;
			cin>>x;
			if(obj.search(x))
			{
				cout<<"present "<<endl;
			}
			else
			{
				cout<<"not present"<<endl;
			}
			break;
		}
		case 2:
		{
			cout<<"Enter key to get attribute"<<endl;
			cin>>x;
			obj.ret(x);
			break;
		}
		case 3:
		{
			cout<<"Enter key to modify attribute"<<endl;
			cin>>x;
			obj.modify(x);
			obj.display();
			break;
		}
		case 4:
		{
			cout<<"Enter key to insert"<<endl;
			cin>>x;
			cout<<"Enter attribute"<<endl;
			cin>>y;
			obj.insert(x,y);
			obj.display();
			break;
		}
		case 5:
		{
			cout<<"Enter key to delete"<<endl;
				cin>>x;
				obj.del(x);
				obj.display();
				break;

		}
		case 6:
		{
			exit(1);
		}
		}


	}

	}
	else
	{
		obj.create(1);
		obj.display();
		while(1)
			{
				cout<<"Enter 1.search name\n 2.retrive attributes\n 3. modify attributes \n 4.Insert entry\n 5.Delete Entery\n 6.Exit"<<endl;
				cin>>a;
				switch(a)
				{
				case 1:
				{
					cout<<"Enter name to search"<<endl;
					cin>>x;
					if(obj.search(x))
					{
						cout<<"present "<<endl;
					}
					else
					{
						cout<<"not present"<<endl;
					}
					break;
				}
				case 2:
				{
					cout<<"Enter key to get attribute"<<endl;
					cin>>x;
					obj.ret(x);
					break;
				}
				case 3:
				{
					cout<<"Enter key to modify attribute"<<endl;
					cin>>x;
					obj.modify(x);
					obj.display();
					break;
				}
				case 4:
				{
					cout<<"Enter key to insert"<<endl;
					cin>>x;
					cout<<"Enter attribute"<<endl;
					cin>>y;
					obj.insert1(x,y);
					obj.display();
					break;
				}
				case 5:
				{
					cout<<"Enter key to delete"<<endl;
						cin>>x;
						obj.del(x);
						obj.display();
						break;

				}
				case 6:
				{
					exit(1);
				}
			}
		}

	}

	return 0;
}
