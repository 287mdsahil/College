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
		cout<<"Item quantity:\t"<quantity<<endl;
		cout<<"Item rate:\t"<<rate<<endl;
		return;
	}

	void setPrice(float p){
		rate = p;
		return;
	}

	int setQuantity(int q){
		quantity = p;
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

}


class itemList{
	item list[Max];
	int cnt;

	public:

	//constructor
	itemList(){
		cnt = 0;
	}

	//takes input for the list
	void prepareList(){
		item t;
		system('clear');
		while(1){
			t.getItem();
			cout<<"\nEnter more items(y/n)? :";
			list[cnt] = t;
			cnt++;
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
			if(c==list[i].code){
				return i;
			}
		}
		return -1;
	}

	//search using name; returns the index of the item
	int searchItem(string n){
		for(int i=0;i<cnt;i++){
			if(n==list[i].name)
				return i;
		}
		return -1;
	}
}

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
}

class order{
	orderLine list[Max];
	int cnt;

	public:

	
}
int main(){
	return 0;
}