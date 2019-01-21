#include<iostream>

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
	
	complex operator + (const complex c2)
	{
		complex dummy;
		dummy.real=real+c2.real;
		dummy.img=img+c2.img;
		return dummy;
	}
	
	complex operator - (const complex c2)
	{
		complex dummy;
		dummy.real=real-c2.real;
		dummy.img=img-c2.img;
		return dummy;
	}
	
};


int main()
{
	class complex t1,t2;
	t1.input();
	t2.input();
	
	class complex t3;
	t3=t1+t2;
	
	t3.display();
	t3=t1-t2;
	t3.display();
	return 0;
}
