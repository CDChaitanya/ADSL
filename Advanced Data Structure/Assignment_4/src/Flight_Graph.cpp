//============================================================================
// Name        : Flight_Graph.cpp
// Author      : 21418
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>        // ONLY SOURCE ADDITION IS FOR DIRECTED
#include <string>          // SOURCE & DEST ADDITION IS FOR UNDIRECTED
#include <cstdlib>
using namespace std;

class node
{
	string name;
	int num;
	int time;
	node* next;
public:
	node(string str,int vnum)
	{
		name=str;
		num=vnum;
		time=0;
		next=NULL;
	}
	friend class graph;
};

class graph
{
	node *g[10];
	int vertex;
public:
	graph(int x)
{
		vertex=x;
		string s;
		for(int i=0; i<x ; i++)
		{
			cout<<"ENTER NAME "<<i+1<<"th CITY"<<endl;
			cin>>s;
			g[i]=new node(s,i);
		}
}
	void add_edge(string s, string d ,int t)
	{
		int i=0;
		do            // SOURCE
		{
			if(g[i]->name == s)          // DO WHILE IS ESSENTIAL
				break;
			else
				i++;
		}while(1);

		cout<<i<<endl;          // != CAN'T BE OVERLOADED FOR STR
                                // HENCE IF CONDITION IS USED
		int j=0;
		do            // DESTINATION
		{
			if(g[j]->name == d)
				break;
			else
				j++;
		}while(1);

		node *temp;
		temp=g[i];
		node* neww=new node(d,j);
		neww->time=t;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=neww;
	}

	void create(int n,int edges,int edg=0)
	{
		string s,d;
		int t;
		int ee=edg+edges;
		if(  ee <= (n*(n-1))/2 )
		{
			if(edg == 0)
			{
				for(int i=0 ; i<edges; i++)          // limit change
				{
					cout<<"ENTER SOURCE AND DESTINATION CITY"<<endl;
					cin>>s;
					cin.ignore();
					cin>>d;
					cin.ignore();

					cout<<"ENTER THE TIME"<<endl;
					cin>>t;

					add_edge(s,d,t);
					add_edge(d,s,t);          // ESSENTIAL FOR UNDIRECTED
				}
			}
			else
			{
				for(int i=0 ; i<edg; i++)            // limit change
				{
					cout<<"ENTER SOURCE AND DESTINATION CITY"<<endl;
					cin>>s;
					cin.ignore();
					cin>>d;
					cin.ignore();

					cout<<"ENTER THE TIME"<<endl;
					cin>>t;

					add_edge(s,d,t);
					add_edge(d,s,t);          // ESSENTIAL FOR UNDIRECTED
				}
			}
		}
	}

	void insert_vertex(int n)
	{
		string s;
		int i=0;
		while(i<n)
		{
			i++;
		}
		cout<<"ENTER NAME "<<i+1<<"th CITY"<<endl;
		cin>>s;
		g[i]=new node(s,i);
		vertex++;
	}
	int ret_ver()
	{
		return vertex;
	}

	void diplay_list(int vn)
	{
		node *temp=g[vn];
		while(temp != NULL)
		{
			cout<<temp->name<<"##"<<temp->time<<"  ";
			temp=temp->next;
		}
	}

	void display(int x)
	{
		for(int i=0 ;i<x ;i++)
		{
			diplay_list(i);
			cout<<endl;
		}
	}
	void BFS(string x)
	{
		int i=0;
		do            // SOURCE
		{
			if(g[i]->name == x)          // DO WHILE IS ESSENTIAL
				break;
			else
				i++;
		}while(1);
		cout<<i<<endl;
		int src=i;

		int visited[20];
		for(int j=0 ;j<20;j++)
		{
			visited[j]=0;
		}

		int q[20];
		int f=0,r=-1;                      // QUEUE CREATION

		q[++r]=src;
		int p;
		while(r != -1)   // empty condition
		{
			p=q[f++];
			if(f==r+1)
			{
				f=0;
				r=-1;
			}
			cout<<g[p]->name<<endl;
			visited[src]=1;
			node *temp=g[p];
			while(temp != NULL)
			{
				if(visited[temp->num] == 0)
				{
					q[++r]=temp->num;
					visited[temp->num]=1;
				}
				temp=temp->next;
			}
		}
	}
	void DFS1(string x)
	{
		int visited[20];
		for(int j=0 ;j<20;j++)
		{
			visited[j]=0;
		}
		DFS(x,visited);
	}
	void DFS(string x , int visited[])
	{
		int i=0;
		do            // SOURCE
		{
			if(g[i]->name == x)          // DO WHILE IS ESSENTIAL
				break;
			else
				i++;
		}while(1);
		int src=i;
		cout<<x<<endl;
		node* temp=g[i];

		visited[src]=1;
		while(temp != NULL)
		{
			if(visited[temp->num] == 0)
			{
				DFS(temp->name , visited);
			}
			temp=temp->next;
		}
	}
	void outdegree(int n)
	{
		int cnt;
		int out[n];
		for(int i=0;i<n;i++)
		{
			cnt=0;
			node* temp=g[i];
			while(temp != NULL)
			{
				cnt++;
				temp=temp->next;
			}
			out[i]=cnt-1;           // -1 for self node
		}
		for(int i=0;i<n;i++)
		{
			cout<<g[i]->name<<" => "<<out[i]<<endl;
		}
	}

	void indegree(int n)
	{
		int cnt;
		int in[n];
		for(int i=0;i<n;i++)
		{
			cnt=0;
			node* temp=g[i];
			while(temp != NULL)
			{
				cnt++;
				temp=temp->next;
			}
			in[i]=cnt-1;           // -1 for self node
		}
		for(int i=0;i<n;i++)
		{
			cout<<g[i]->name<<" => "<<in[i]<<endl;
		}
	}

	void delete_path(string s,string d)
	{
		int i=0;
		do            // SOURCE
		{
			if(g[i]->name == s)          // DO WHILE IS ESSENTIAL
				break;
			else
				i++;
		}while(1);

		node* p;
		node* q;
		if(g[i]->name == d)
		{
			p=g[i];
			g[i]=g[i]->next;
			delete p;
		}
		else
		{
			p=g[i];
			while(p != NULL)
			{
				if(p->name == d)
				{
					q->next=p->next;
					delete p;
				}
				q=p;
				p=p->next;
			}
		}
	}
	void del_path()
	{
		string u,v;
		cout<<"SOURCE "<<endl;
		cin>>u;
		cout<<"DESTINATION "<<endl;
		cin>>v;
		delete_path(u,v);
		delete_path(v,u);
	}
	void del_ver()
	{
		string v;
		cout<<"VERTEX "<<endl;
		cin>>v;
		int i=0;
		do            // SOURCE
		{
			if(g[i]->name == v)          // DO WHILE IS ESSENTIAL
				break;
			else
				i++;
		}while(1);
		node* p=g[i];
		node* q;
		while(p != NULL)                // DELETES WHOLE LL FOR THAT VERTEX
		{
			q=p;
			p=p->next;
			delete q;
		}
		vertex--;
		for(int j=0;j<vertex;j++)
		{
			node*p=g[j];
			node*q;
			while(p != NULL)
			{
				if(p->name == v)
				{
					q->next=p->next;
					delete p;
				}
				q=p;
				p=p->next;
			}
		}
	}
};

int main()
{
	int vertices;
	int edges;
	string start;
	int ch;

	cout<<"TOTAL NUMBER OF VERTICES"<<endl;
	cin>>vertices;
	graph g(vertices);

	cout<<"NUMBER OF EDGES"<<endl;
	cin>>edges;
	g.create(vertices,edges);

	do
	{
		vertices=g.ret_ver();
		cout<<"1. INSERT VERTEX"<<endl;
		cout<<"2. INSERT EDGE"<<endl;
		cout<<"3. DISPLAY"<<endl;
		cout<<"4. BFS"<<endl;
		cout<<"5. DFS"<<endl;
		cout<<"6. OUT-DEGREE"<<endl;
		cout<<"7. IN-DEGREE"<<endl;
		cout<<"8. DELETE EDGE"<<endl;
		cout<<"9. DELETE VERTEX"<<endl;
		cout<<"10. EXIT"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			g.insert_vertex(vertices);
			break;
		}
		case 2:
		{
			int edg;
			cout<<"NUMBER OF EDGES TO BE ADDED "<<endl;
			cin>>edg;
			g.create(vertices,edges,edg);
			break;
		}
		case 3:
		{
			cout<<"####### DISPLAY ########"<<endl;
			g.display(vertices);
			break;
		}
		case 4:
		{
			cout<<"ENTER STARETING VERTEX"<<endl;
			cin>>start;
			cout<<"BFS =>"<<endl;
			g.BFS(start);
			break;
		}
		case 5:
		{
			cout<<"ENTER STARETING VERTEX"<<endl;
			cin>>start;
			cout<<"DFS =>"<<endl;
			g.DFS1(start);
			break;
		}
		case 6:
		{
			cout<<"OUT DEGREE OF EACH ELEMENT"<<endl;
			g.outdegree(vertices);
			break;
		}
		case 7:
		{
			cout<<"IN DEGREE OF EACH ELEMENT"<<endl;
			g.indegree(vertices);
			break;
		}
		case 8:
		{
			g.del_path();
			break;
		}
		case 9:
		{
			g.del_ver();
			break;
		}
		case 10:
		{
			exit(1);
			break;
		}
		default:
			cout<<"INVALID INPUT "<<endl;
		}
	}while(1);

	return 0;
}
