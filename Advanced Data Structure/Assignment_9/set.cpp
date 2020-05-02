#include <iostream>
using namespace std ;
#define max 50
template<class t>
class set
{
    t data[max];
    int n;
    public:
    set()
    {
        n=-1;            // for FOR loop
    }
    bool insert (t element)
    {
        if(n >=max)
        {
            cout<<"OVERFLOW SET IS FULL"<<endl;
            return false;
        }
        data[++n]=element;
        return true;
    }
    void input(int x)
    {
        t element;
        for(int i=0;i<x;i++)
        {
            cout<<"ENTER THE ELEMENT "<<endl;
            cin>>element;
            insert(element);
        }
    }
    void print()
    {
        for(int i=0;i<=n;i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }
    set<t> uni(set<t> s1, set<t> s2)
    {
        set <t> s3;
        for(int i=0;i<=s1.n;i++)
        {
            s3.insert(s1.data[i]);
        }
        for(int i=0;i<=s2.n;i++)
        {
            int flag=0;
            for(int j=0;j<=s1.n;j++)
            {
                if(s1.data[j] == s2.data[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                s3.insert(s2.data[i]);
            }            
        }
        return s3;
    }
    set<t> intersection (set<t> s1,set<t> s2)
    {
        set<t> s3;
        for(int i=0; i<=s1.n; i++)
        {
            for(int j=0; j<=s2.n; j++)
            {
                if(s1.data[i]==s2.data[j])
                {
                    s3.insert(s1.data[i]);
                    break;
                }
            }
        }
        return s3;
    }
    set<t> diff(set<t> s1, set<t> s2)
    {
        set <t> s3;
        for(int i=0; i<=s1.n ;i++)
        {
            int flag=0;
            for(int j=0; j<=s2.n;  j++)
            {
                if(s1.data[i] == s2.data[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                s3.insert(s1.data[i]);
            }
        }
        return s3;
    }
    bool subset(set<t> s1, set<t> s2)
    {
        int i=0,j=0;
        for(j=0;j<=s2.n;j++)
        {
            for(i=0;i<=s1.n;i++)
            {
                if(s2.data[j] == s1.data[i])
                    break;
            }
            if(i == s1.n)
                return 0;
        }
        return 1;
    }
    bool remove(t element)
    {
        if(n==-1)
        {
            cout<<"UNDERFLOW CAN'T PERFORM DELETION"<<endl;
            return false;
        }
        for(int i=0;i<=n;i++)
        {
            if(data[i]==element)
            {
                for(int j=i;j<=n;j++)
                {
                    data[j]=data[j+1];
                }
                n--;
                return true;
            }
        }
        return false;
    }
    bool contains(t element)
    {
        for(int i=0;i<=n;i++)
        {
            if(data[i] == element)
                return true;
        }
        return false;
    }
    int size()
    {
        return n+1;
    }
};
int main()
{
    set<int> s1,s2,s3;
    int choice,element;
	cout<<"ENTER NUMBER OF ELEMENT IN SET 1"<<endl;
	cin>>element;//element is used for taking size
	s1.input(element);
	cout<<"ENTER NUMBER OF ELEMENT IN SET 2"<<endl;
	cin>>element;//element is used for taking size
	s2.input(element); 
    do
    {
		cout<<"##### SET OPERATIONS ######"<<endl;
		cout<<"1. INSERT"<<endl;
		cout<<"2. REMOVE"<<endl;
		cout<<"3. SEARCH"<<endl;
		cout<<"4. SIZE OF SET"<<endl;
		cout<<"5. INTERSECTION"<<endl;
		cout<<"6. UNION"<<endl;
		cout<<"7. DIFFERENCE"<<endl;
		cout<<"8. CHECK IF SUBSET"<<endl;
		cout<<" ENTER YOUR CHOICE "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"ENTER ELEMENT TO INSERT"<<endl;
                cin>>element;
                if(s1.insert(element))
                    cout<<element<<" INSERTED"<<endl;
                else
                    cout<<"INSERTION FAILED"<<endl;
                break;
            }
            case 2:
            {
                cout<<"ENTER ELEMENT TO DELETE"<<endl;
                cin>>element;
                if(s1.remove(element))
                    cout<<element<<" DELETED"<<endl;
                else
                    cout<<"DELETION FAILED"<<endl;
                break;
            }
            case 3:
            {
                cout<<"ENTER ELEMENT TO SEARCH"<<endl;
                cin>>element;
                if(s1.contains(element))
                    cout<<element<<" IS PRESENT"<<endl;
                else
                    cout<<"ELEMENT IS NOT PRESENT"<<endl;
                break;
            }
            case 4:
            {
                cout<<"SIZE"<<" "<<s1.size()<<endl;
                break;
            }
            case 5:
            {
                s3=s1.intersection(s1,s2);
                cout<<"ELEMENTS IN SET 1"<<endl;
                s1.print();
                cout<<"ELEMETS IN SET 2"<<endl;
                s2.print();
                cout<<"INTERSECTION"<<endl;
                s3.print();
                break;
            }
            case 6:
            {
                s3=s1.uni(s1,s2);
                cout<<"ELEMENTS IN SET 1"<<endl;
                s1.print();
                cout<<"ELEMETS IN SET 2"<<endl;
                s2.print();
                cout<<"UNION"<<endl;
                s3.print();
                break;
            }
            case 7:
            {
                s3=s1.diff(s1,s2);
                cout<<"ELEMENTS IN SET 1"<<endl;
                s1.print();
                cout<<"ELEMETS IN SET 2"<<endl;
                s2.print();
                cout<<"DIFFERENCE"<<endl;
                s3.print();
                break;
            }
            case 8:
            {   
            	cout<<"ENTER NUMBER OF ELEMENTS FOR CHECKING SUBSET"<<endl;
	            cin>>element;//element is used for taking size
            	s3.input(element);
                if(s3.subset(s1,s3))
                    cout<<"YES THIS IS SUBSET"<<endl;
                else
                    cout<<"THIS IS NOT A SUBSET"<<endl;
                break;
            }
            case 9:
            {
                exit(1);
                break;
            }
            default:
                cout<<"INVALID INPUT"<<endl;
        }
    } while (1);       
    return 0;
}