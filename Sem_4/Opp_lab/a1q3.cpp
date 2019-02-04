#include<iostream>
#include<string>
#define Max 20
using namespace std;


class item{
	string code;
	string name;
	int quantity;
	float rate;
	
	public:
	
	void getItem(){
		cout<<"Enter the code: ";
		cin>>code;
		cout<<"Enter the name: ";
		cin>>name;
		cout<<"Enter the quantity: ";
		cin>>quantity;
		cout<<"Enter the rate: ";
		cin>>rate;
		return;
	}

	void showItem(){
		cout<<"Item code:\t"<<code<<endl;
		cout<<"Item name:\t"<<name<<endl;
		cout<<"Item quantity:\t"<<quantity<<endl;
		cout<<"Item rate:\t"<<rate<<endl;
		return;
	}

	void setPrice(float p){
		rate = p;
		return;
	}

	void setQuantity(int q){
		quantity = q;
		return;
	}

	string getCode()
	{
		return code;
	}

	string getName(){
		return name;
	}

	float getRate(){
		return rate;
	}

	int getQuantity(){
		return quantity;
	}

};


class itemList{
	item list[Max];
	int cnt;
	friend class order;

	public:

	//constructor
	itemList(){
		cnt = 0;
	}

	//takes input for the list
	void prepareList(){
		item t;
		while(1){
			t.getItem();
			list[cnt] = t;
			cnt++;
			cout<<"\nEnter more items(y/n)? :";
			char choice;
			cin>>choice;
			if(choice != 'y' && choice != 'Y')
				break;
			cout<<endl;	
		}
		return;
	}

	//returns -1 if the not doesnot exist
	int findCode(string c){
		for(int i=0;i<cnt;i++){
			if(c==list[i].getCode()){
				return i;
			}
		}
		return -1;
	}

	//search using name; returns the index of the item
	int searchItem(string n){
		for(int i=0;i<cnt;i++){
			if(n==list[i].getName())
				return i;
		}
		return -1;
	}
};

class orderLine{
	string code;
	int quantity;

	public:

	void getOrderLine(){
		cout<<"Enter the item code: ";
		cin>>code;
		cout<<"Enter the quantity: ";
		cin>>quantity;
		return;
	}
};

class order{
	orderLine list[Max];
	int cnt;

	public:

	order(){
		cnt=0;
	}

	void collectOrder(){
		orderLine t;
		while(1){
			t.getOrderLine();
			list[cnt] = t;
			cnt++;
			cout<<"\nEnter more items(y/n)? :";
			char choice;
			cin>>choice;
			if(choice != 'y' && choice != 'Y')
				break;
			cout<<endl;	
		}
		return;
	}
};

class salesInterface{

	itemList l;
	order o;

	public:
	
	void loginMenu(){

		while(1){
			system("clear");
			cout<<"------LOGIN---------"<<endl;
			cout<<"1. Admin login"<<endl;
			cout<<"2. User login"<<endl;
			cout<<"3. Exit"<<endl;
			cout<<"Enter choice: ";

			int choice;
			cin>>choice;
			switch (choice)
			{
				case 1:
					adminMenu();
					break;
				case 3:
					return;
				default:
					cout<<"Invalid Input!"<<endl;
					getchar();
					getchar();
					break;
			}
		}
	}

	void adminMenu(){
		while(1){
			system("clear");
			cout<<"------Admin---------"<<endl;
			cout<<"1. Enter item"<<endl;
			cout<<"2. Update item"<<endl;
			cout<<"3. Exit"<<endl;
			cout<<"Enter choice: ";
			int choice;
			cin>>choice;
			switch(choice){
				case 1:
					l.prepareList();
					break;
				case 3:
					return;
				default:
					cout<<"Invalid Input!"<<endl;
					getchar();
					getchar();
			}
		}
	}
};


int main(){
	salesInterface sales;
	sales.loginMenu();
	return 0;
}