#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;


//complex class
class complex
{
	float real;
	float img;
	
	public :
	//temporary input 
	void input()
	{
		cin>>real>>img;
	}
	//temporary display
	void display()
	{
		cout<<real<<" + i"<<img;
	}
	
	complex operator + (const complex &c2)
	{
		complex dummy;
		dummy.real=real+c2.real;
		dummy.img=img+c2.img;
		return dummy;
	}
	
	complex operator - (const complex &c2)
	{
		complex dummy;
		dummy.real=real-c2.real;
		dummy.img=img-c2.img;
		return dummy;
	}
	
	friend ostream& operator << (ostream &o, const complex &c)
	{
		o<<c.real;
		if(c.img<0)	o<<"-i"<<-(c.img);
		else	o<<"+i"<<c.img;
		return o;
	}
	
	friend istream& operator >> (istream &i, complex &c)
	{
		string s,rs,is;
		i>>s;
		int n=s.length();
		int r_init=0,r_end=0,i_init=0,i_end=0,i_neg=0,i_flag=0;
		for(int j=0;j<n;j++)
		{
			if(s[j]=='i')
			{
				i_flag=1;
				i_init=j+1;
				i_end=n;
				if(j!=0)
				{	
					if(s[j-1]=='-')
						i_neg=1;
					if(j>1)
						r_end=j-1;
				}
				else r_end=0;
			
			}
			if(i_flag==0 && j==n-1)
			{
				r_end=n;
			}
		}
		rs=s.substr(r_init,(r_end-r_init));
		is=s.substr(i_init,(i_end-i_init));
		//cout<<r_init<<" "<<r_end<<" | "<<i_init<<" "<<i_end<<endl;
		//cout<<":-\t"<<rs<<" "<<is<<endl;
		if(rs!="") c.real=stof(rs);
		else c.real=0;
		if(is!="") c.img=stof(is);
		else c.img=0;
		if(i_neg) c.img=-c.img;
		return i;		
	}
};


int main()
{
	//class complex t1,t2;
	//t1.input();
	//t2.input();
	
	//complex t3;
	//t3=t1+t2;
	
	//cout<<t3<<endl;
	//cin>>t3;
	//cout<<t3<<endl;
	
	
	while(1)
	{
		int x;
		system("clear");
		cout<<"MENU:\n";
		cout<<"1.Input\n2.Display\n3.Add\n4.Substract\n5.Exit\nEnter choice: ";
		cin>>x;
		
		complex c1,c2;
		switch(x)
		{
			case 1: cin>>c1;break;
			case 2: cout<<c1<<endl;getchar();getchar();break;
			case 3: cin>>c2;c1=(c1+c2);cout<<c1<<endl;getchar();getchar();break;
			case 4: cin>>c2;c1=(c1-c2);cout<<c1<<endl;getchar();getchar();break;
			case 5: exit(0);
		}
	}
	return 0;
}
