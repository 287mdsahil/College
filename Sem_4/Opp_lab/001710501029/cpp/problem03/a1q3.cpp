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

	void setRate(float p){
		rate = p;
		return;
	}

	void setQuantity(int q){
		quantity += q;
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
	friend class salesInterface;
	friend class orderLine;

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
			if(findCode(t.getCode())!=-1){
				cout<<"Code already exists! Insertion Failed!"<<endl;
				getchar();
				getchar();
			}
			else{
				list[cnt] = t;
				cnt++;
			}
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

	//update items
	void updateItem(){
		string c;
		cout<<"Enter the code of the item: ";
		cin>>c;
		int i = findCode(c);
		if(i==-1){
			cout<<"Item doesnot exist!"<<endl;
			getchar();
			getchar();
			return;
		}
		cout<<endl;
		cout<<"1. Append quantity"<<endl;
		cout<<"2. Update rate"<<endl;
		cout<<"Enter choice: ";
		int choice;
		cin>>choice;
		switch (choice)
		{
			case 1:
				int q;
				cout<<"Append quantity by: ";
				cin>>q;
				list[i].setQuantity(q);
				cout<<"New quantity: "<<list[i].getQuantity()<<endl;
				getchar();
				getchar();
				break;
			case 2:
				int r;
				cout<<"Enter new rate: ";
				cin>>r;
				list[i].setRate(r);
				cout<<"New rate: "<<list[i].getRate()<<endl;
				getchar();
				getchar();
				break;
			default:
				cout<<"Invalid Input!"<<endl;
				getchar();
				getchar();
				break;
		}
		return;
	}

	void showItems(){
		for(int i=0;i<cnt;i++){
			cout<<endl;
			list[i].showItem();
		}
		getchar();
		getchar();
	}
};

class orderLine{
	string code;
	int quantity;

	public:

	int getOrderLine(itemList l){
		cout<<"Enter the item code: ";
		string c;
		cin>>c;
		int i = l.findCode(c);
		if(i==-1){
			cout<<"Item doesnot exist!"<<endl;
			getchar();
			getchar();
			return 0;
		}
		cout<<"Enter the quantity: ";
		int q;
		cin>>q;
		if(q>l.list[i].getQuantity()){
			cout<<"Inadequate supply!"<<endl;
			getchar();
			getchar();
			return 0;
		}
		code = c;
		quantity = q;
		return 1;
	}

	string getCode(){
		return code;
	}

	int getQuantity(){
		return quantity;
	}

	void showOrderline(){
		cout<<"Item code:\t"<<code;
		cout<<"\t\t";
		cout<<"Item quantity:\t"<<quantity;
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

	void collectOrder(itemList l){
		orderLine t;
		while(1){
			if(t.getOrderLine(l)==1){
				list[cnt] = t;
				cnt++;
			}
			cout<<"\nEnter more items(y/n)? :";
			char choice;
			cin>>choice;
			if(choice != 'y' && choice != 'Y')
				break;
			cout<<endl;	
		}
		return;
	}

	void orderDetails(itemList l){
		cout<<endl;
		int total = 0;
		cout<<"----------------------------------INVOICE--------------------------------"<<endl<<endl;
		for(int i=0;i<cnt;i++){
			list[i].showOrderline();
			float r;
			string c = list[i].getCode();
			int ind = l.findCode(c);
			r = l.list[ind].getRate();
			float price = list[i].getQuantity()*(r);
			cout<<"\tPrice: "<<price<<endl;
			total+=price;
			cout<<endl;
		}

		cout<<"\t\t\t\t\tTotal: "<<total<<endl;
		getchar();
		getchar();
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
				case 2:
					userMenu();
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
			cout<<"3. Show inventory"<<endl;
			cout<<"4. logout"<<endl;
			cout<<"Enter choice: ";
			int choice;
			cin>>choice;
			switch(choice){
				case 1:
					l.prepareList();
					break;
				case 2:
					l.updateItem();
					break;
				case 3:
					l.showItems();
					break;
				case 4:
					return;
				default:
					cout<<"Invalid Input!"<<endl;
					getchar();
					getchar();
			}
		}
	}

	void userMenu(){
		while(1){
			system("clear");
			cout<<"------User---------"<<endl;
			cout<<"1. Show all item"<<endl;
			cout<<"2. Show item"<<endl;
			cout<<"3. Place order"<<endl;
			cout<<"4. Show order detalis"<<endl;
			cout<<"5. Logout"<<endl;
			cout<<"Enter choice: ";
			int choice;
			cin>>choice;
			switch(choice){
				case 1:
					l.showItems();
					break;
				case 2:
					{
						cout<<"Enter the item code: ";
						string c;
						cin>>c;
						int i=l.findCode(c);
						if(i==-1){
							cout<<"Item doesnot exits!"<<endl;
						}
						else{
							l.list[i].showItem();
						}
						getchar();
						getchar();
						break;
					}
				case 3:
					o.collectOrder(l);
					break;
				case 4:
					o.orderDetails(l);
					break;
				case 5:
					return;
				default:
					cout<<"Invalid Input!"<<endl;
					getchar();
					getchar();
					break;
			}
		}
	}
};


int main(){
	salesInterface sales;
	sales.loginMenu();
	return 0;
}