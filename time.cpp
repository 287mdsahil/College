#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;

class mytime{
	int hours;
	int mins;
	int secs;
	
	public:
	void input(){
		string ss;
		cout<<"Enter the time:- ";
		cin>>ss;
		if(ss[8]==':'){
			//12 hour format
			
			if(ss[2]!=':' || ss[5]!=':' || ss[10]!='m' || (ss[9]!='a' && ss[9]!='p')){
				cout<<"Invalid format1!"<<endl;
				getchar();
				getchar();
				return;
			}
			int h,m,s;
			if(ss[0]>='0' && ss[0] <='1' && ss[1]>='0' && ss[0] <='9'){
				h=int(ss[0]-'0')*10+int(ss[1]-'0');
				if(h>12){
					cout<<"Invalid Value!"<<endl;
					getchar();
					getchar();
					return;
				}
			}
			else{
				cout<<"Invalid format2!"<<endl;
				getchar();
				getchar();
				return;
			}
			if(ss[3]>='0' && ss[3] <='5' && ss[4]>='0' && ss[4] <='9')
				m=int(ss[3]-'0')*10+int(ss[4]-'0');
			else{
				cout<<"Invalid format3!"<<endl;
				getchar();
				getchar();
				return;
			}
			if(ss[6]>='0' && ss[6] <='5' && ss[7]>='0' && ss[7] <='9')
				s=int(ss[6]-'0')*10+int(ss[7]-'0');
			else{
				cout<<"Invalid format4!"<<endl;
				getchar();
				getchar();
				return;
			}
			if(ss[9]=='p')
				h=(h%12+12)%24;
			if(h>11 && ss[9]=='a'){
				cout<<"Invalid format4!"<<endl;
				getchar();
				getchar();
				return;
			}
			hours=h;
			mins=m;
			secs=s;
		}
		else{
			//24 hour format
			if(ss[2]!=':' || ss[5]!=':'){
				cout<<"Invalid format5!"<<endl;
				getchar();
				getchar();
				return;
			}
			int h,m,s;
			if(ss[0]>='0' && ss[0] <='2' && ss[1]>='0' && ss[0] <='9')
			{
				h=int(ss[0]-'0')*10+int(ss[1]-'0');
				if(h>24){
					cout<<"Invalid Value2!"<<endl;
					getchar();
					getchar();
					return;
				}
			}
			else{
				cout<<"Invalid format5!"<<endl;
				getchar();
				getchar();
				return;
			}
			if(ss[3]>='0' && ss[3] <='5' && ss[4]>='0' && ss[4] <='9')
				m=int(ss[3]-'0')*10+int(ss[4]-'0');
			else{
				cout<<"Invalid format6!"<<endl;
				getchar();
				getchar();
				return;
			}
			if(ss[6]>='0' && ss[6] <='5' && ss[7]>='0' && ss[7] <='9')
				s=int(ss[6]-'0')*10+int(ss[7]-'0');
			else{
				cout<<"Invalid format7!"<<endl;
				getchar();
				getchar();
				return;
			}
			hours=h;
			mins=m;
			secs=s;
		}
	}
	
	
	void display24(){
		cout<<"Time:- "<<hours<<":"<<mins<<":"<<secs<<endl;
		getchar();
		getchar();
	}
	
	void display12(){
		if(hours>12)
			cout<<"Time:- "<<hours-12<<":"<<mins<<":"<<secs<<":pm"<<endl;
		else if(hours==12)
			cout<<"Time:- "<<hours<<":"<<mins<<":"<<secs<<":pm"<<endl;
		else if(hours==0)
			cout<<"Time:- "<<hours+12<<":"<<mins<<":"<<secs<<":am"<<endl;
		else
			cout<<"Time:- "<<hours<<":"<<mins<<":"<<secs<<":am"<<endl;
		getchar();
		getchar();
	}
	
	void addmins(){
		int m;
		cout<<"Enter the mins to add:- ";
		cin>>m;
		int h=m/60;
		m=m%60;
		hours=(hours+h+(mins+m)/60)%24;
		mins=(mins+m)%60;
	}
	
	void comptime(){
		// current date/time based on current system
   		time_t now = time(0);
   
  	 	// convert now to string form
   		char* dt = ctime(&now);
   		dt=dt.substr(11,8);
   		cout<<dt<<endl;
   		getchar();
   		getchar();
	}
};



//main function----------------------------------------------------------
int main(){
	class mytime t;
	while(1){
		system("clear");
		cout<<"Menu:\n1.input\n2.display in 24 hour format\n3.display in 12 hour format\n4.add minutes\n5.compare with system time\n6.exit\n";
		int x;
		cout<<"Enter choice: ";
		cin>>x;
		switch(x)
		{
			case 1: t.input();break;
			case 2: t.display24();break;
			case 3: t.display12();break;
			case 4: t.addmins();break;
			case 5: t.comptime();break;
			case 6: return 0;
		}	
	}
	
	return 0;
}
