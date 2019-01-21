#include<iostream>
#include<string.h>

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
	
	friend void operator >> (istream &i, complex &c)
	{
		i>>c.real>>c.img;
		return ;
	}
};


int main()
{
	//class complex t1,t2;
	//t1.input();
	//t2.input();
	
	complex t3;
	//t3=t1+t2;
	
	cout<<t3<<endl;
	cin>>t3;
	cout<<t3<<endl;
	return 0;
}
