#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class entry
{
	string word;
	string meaning;
	friend class dictionary;
};
class dictionary
{
	entry e[26];
	int n;
public:
	dictionary()
	{
		n=0;
	}
	int hash_function(string w)
	{
		int x=w[0];
		int i;
		if(x<=90 && x>=65)
		{
			i=x-65;
		}
		if(x<=122 && x>=97)
		{
			i=x-97;
		}
		return i;
	}
	void getdata_without_replacement()
	{
		cout<<"GIVE INPUT -1 FOR MENU"<<endl;
		string w,m;
		int i;
		while(1)
		{
			cout<<"ENTER THE WORD TO BE ADDED"<<endl;
			cin>>w;
			if(w=="-1")
				return;
			if(n>=26)
			{
				cout<<"MAX LIMIT REACHED"<<endl;
				break;
			}
			cout<<"ENTER MEANING "<<endl;
			cin>>m;
			n++;
			i=hash_function(w);
			int j=i;
			while(e[j].word != "\0")
			{
				j++;
			}
			e[j].word=w;
			e[j].meaning=m;
		}
	}
	void getdata_with_replacement()
	{
		cout<<"GIVE INPUT -1 FOR MENU"<<endl;
		string w,m;
		int i;
		while(1)
		{
			cout<<"ENTER THE WORD TO BE ADDED"<<endl;
			cin>>w;
			if(w=="-1")
				break;
			if(n>=26)
			{
				cout<<"MAX LIMIT REACHED"<<endl;
				break;
			}
			cout<<"ENTER MEANING "<<endl;
			cin>>m;
			n++;

			int flag=0;
			i=hash_function(w);
			if(e[i].word=="\0")
			{
				e[i].word=w;
				e[i].meaning=m;
			}
			else
			{
				entry temp;
				if(hash_function(e[i].word)==i)
				{
					flag=0;
				}
				else
				{
					temp=e[i];
					e[i].word=w;
					e[i].meaning=m;
					flag=1;
				}
				int j=i+1;
				while(e[j].word!="\0")
				{
					j++;
				}
				if(flag==0)
				{
					e[j].word=w;
					e[j].meaning=m;
				}
				else
				{
					e[j]=temp;
				}
			}
		}
	}
	void search()
	{
		string s;
		int cnt=0;
		cout<<"ENTER THE WORD TO BE SERCHED"<<endl;
		cin>>s;
		int i=hash_function(s);
		int j=i;
		while(1)
		{
			if(e[j].word =="\0" || j==i+26)
			{
				cout<<"WORD NOT FOUND"<<endl;
				return ;
			}
			if(e[j].word == s)
			{
				cout<<"WORD FOUND"<<endl;
				cnt++;
				cout<<e[j].word<<"  "<<e[j].meaning<<endl;
				cout<<"NUMBER OF COMPARISION ARE "<<cnt<<endl;
				break;
			}
			j++;
			cnt++;
		}
	}
	void modify()
	{
		string s;
		cout<<"ENTER THE WORD TO BE MODIFIED"<<endl;
		cin>>s;
		int i=hash_function(s);
		int j=i;
		while(1)
		{
			if(e[j].word =="\0" || j==i+26)
			{
				cout<<"WORD NOT FOUND"<<endl;
				return ;
			}
			if(e[j].word == s)
			{
				string w;
				cout<<"WORD FOUND"<<endl;
				cout<<"ENTER THE WORD TO BE REPLACED BY"<<endl;
				cin>>w;
				e[j].word=w;
				break;
			}
			j++;
		}
	}
	void delete1()
	{
		string w;
		cout<<"ENTER THE WORD TO BE DELETED"<<endl;
		cin>>w;
		int i=hash_function(w);
		int j=i;
		while(1)
		{
			if(e[j].word =="\0" || j==i+26)
			{
				return ;
			}
			if(e[j].word ==w)
			{
				string temp=w;
				e[j].meaning = "\0";
				e[j].word = "\0";
				delete_(w,j);
				break;
			}
			j++;
		}
	}
	void delete_(string w,int i)
	{
		int count=0;
		int k=i+1;
		while(count<26)
		{
			if(e[k].word=="\0")
			{
				e[i].word="\0";
				e[i].meaning="\0";
				break;
			}
			if(hash_function(e[k].word)==hash_function(w))
			{
				e[i]=e[k];
				delete_(e[k].word,k);
				break;
			}
			k++;
			count++;
		}
	}
	void show()
	{
		string blank="-----";
		for(int i=0;i<26;i++)
		{
			if(e[i].word=="\0")
			{
				cout<<i<<"."<<setw(15)<<blank<<setw(15)<<blank<<endl;
			}
			else
			{
				cout<<i<<"."<<setw(15)<<e[i].word<<setw(15)<<e[i].meaning<<endl;
			}

		}
	}
};
int main()
{
	dictionary d,d1;
	int eee;
	int ch;
	do
	{
		cout<<"1.CREATE WITHOUT REPLACEMENT"<<endl;
		cout<<"2.CREATE WITH REPLACEMENT"<<endl;
		cout<<"3.EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"ENTER 0 TO MAIN MENU"<<endl;
				do
					{
						cout<<"1.CREATE WITHOUT REPLACEMENT"<<endl;
						cout<<"2.DELETE"<<endl;
						cout<<"3.SEARCH"<<endl;
						cout<<"4.MODIFY"<<endl;
						cout<<"5.DISPLAY"<<endl;
						cout<<"6.EXIT"<<endl;
						cout<<"ENTER YOUR CHOICE"<<endl;
						cin>>ch;
						switch(ch)
						{
							case 0:
								eee=0;
								break;
							case 1:
								d.getdata_without_replacement();
								break;
							case 2:
								d.delete1();
								break;
							case 3:
								d.search();
								break;
							case 4:
								d.modify();
								break;
							case 5:
								d.show();
								break;
							case 6:
								exit(1);
								break;
							default:
								cout<<"INVALID INPUT"<<endl;
						}
					}while(eee != 0);
				break;
		    }
			case 2:
			{
				cout<<"ENTER 0 TO MAIN MENU"<<endl;
				do
					{
						cout<<"1.CREATE WITH REPLACEMENT"<<endl;
						cout<<"2.DELETE"<<endl;
						cout<<"3.SEARCH"<<endl;
						cout<<"4.MODIFY"<<endl;
						cout<<"5.DISPLAY"<<endl;
						cout<<"6.EXIT"<<endl;
						cout<<"ENTER YOUR CHOICE"<<endl;
						cin>>ch;
						switch(ch)
						{
							case 0:
								eee=0;
								break;
							case 1:
								d1.getdata_with_replacement();
								break;
							case 2:
								d1.delete1();
								break;
							case 3:
								d1.search();
								break;
							case 4:
								d1.modify();
								break;
							case 5:
								d1.show();
								break;
							case 6:
								exit(1);
								break;
							default:
								cout<<"INVALID INPUT"<<endl;
						}
					}while(eee != 0);
				break;
			}
			case 3:
			{
				exit(1);
				break;
			}
			default:
			{
				cout<<"INVALID INPUT"<<endl;
			}
		}
	}while(1);
}
