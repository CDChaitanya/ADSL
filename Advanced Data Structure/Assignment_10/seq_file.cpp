#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class student
{
    public:
    string name,div,address;
    int roll;
    void getdata()
    {
        cout<<"ROLL NUMBER"<<endl;
        cin>>roll;
        cout<<"NAME"<<endl;
        cin>>name;
        cout<<"DIVISION"<<endl;
        cin>>div;
        cout<<"ADDRESS"<<endl;
        cin>>address;
    }
    void putdata()
    {
        cout<<"########  DETALIS OF A STUDENT  ########"<<endl;
        cout<<"ROLL NO =====>"<<roll<<endl;
        cout<<"NAME ========>"<<name<<endl;
        cout<<"DIVISION ====>"<<div<<endl;
        cout<<"ADDRESS =====>"<<address<<endl; 
    }
};
class file
{
    fstream fp;
    int n;
    public:
    void create()
    {
        student s;
        fp.open("stud.dat",ios::out);
        cout<<"ENTER TOTAL NUMBER OF ENTERIES"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"ENTER DETAILS OF "<<i+1<<" STUDENT"<<endl;
            s.getdata();
            fp.write((char*)&s , sizeof(s));
        }
        fp.close();
    }
    void append()
    {
        student s;
        fp.open("stud.dat",ios::app);
        cout<<"ENTER DETAILS OF "<<n+1<<" STUDENT"<<endl;
        n++;
        s.getdata();
        fp.write((char*)&s , sizeof(s));
        fp.close();
    }
    void display()
    {
        student s;
        fp.open("stud.dat",ios::in);
        while(!fp.eof())
        {
            fp.read((char*)&s , sizeof(s));
            if(!fp.eof())
                s.putdata();
        }
        fp.close();
    }
    void search()
    {
        student s;
        int r,flag;
        cout<<"ENTER THE ROLL NUMBER TO BE SEARHED"<<endl;
        cin>>r;
        fp.open("stud.dat",ios::in);
        while(!fp.eof())
        {
            fp.read((char*)&s , sizeof(s));
            if(!fp.eof()  && s.roll==r)
            {
                flag=1;
                s.putdata();
                break;
            }
        }
        if(flag==0)
            cout<<"STUDENT NOT FOUND"<<endl;
        fp.close();
    }
    void update()
    {
        student s;
        int r,flag;
        cout<<"ENTER THE ROLL NUMBER TO BE UPDATED"<<endl;
        cin>>r;
        fp.open("stud.dat",ios::in | ios::out);
        while(!fp.eof())
        {
            fp.read((char*)&s , sizeof(s));
            if(!fp.eof()  && s.roll==r)
            {
                flag=1;
                cout<<"ENTER NEW DATA"<<endl;
                s.getdata();
                fp.seekp(-1*sizeof(s),ios::cur);
                fp.write((char*)&s , sizeof(s));
                break;
            }
        }
        if(flag==0)
            cout<<"STUDENT NOT FOUND"<<endl;
        fp.close();
    }
    void Delete()
    {
        student s;
        fstream fp1;     // additional stream
        int r,flag;
        cout<<"ENTER THE ROLL NUMBER TO BE DELETED"<<endl;
        cin>>r;
        fp.open("stud.dat",ios::in);
        fp1.open("temp.dat",ios::out);
        while(   fp.read((char*)&s , sizeof(s))  )
        {
            if(s.roll == r)  //condition change
            {
                flag=1;
                continue;
            }
            fp1.write((char*)&s , sizeof(s));
        }
        if(flag==0)
            cout<<"STUDENT NOT FOUND"<<endl;
        fp.close();
        fp1.close();
        remove("stud.dat");
        rename("temp.dat", "stud.dat");
        fp.open("stud.dat",ios::in|ios::ate|ios::out|ios::binary);
    }
};
int main()
{
	file f; 
	int choice;
    do
	{
       cout<<"1. CREATE"<<endl;
       cout<<"2. DISPLAY"<<endl;
       cout<<"3. SEARCH"<<endl;
       cout<<"4. APPEND"<<endl;
       cout<<"5. DELETE"<<endl;
       cout<<"6. UPDATE"<<endl;
       cout<<"ENTER YOUR CHOICE"<<endl;  
	   cin >> choice;
       switch(choice)
       {
            case 1:f.create(); break;
            case 2:f.display(); break;
            case 3:f.search(); break;
            case 4:f.append(); break;
	 	   	case 5:f.Delete();break;
	      	case 6:f.update();break;
            case 7: exit(1);break;
            default: cout<<"INVALID INPUT"<<endl;
       }
    }while(1);
}