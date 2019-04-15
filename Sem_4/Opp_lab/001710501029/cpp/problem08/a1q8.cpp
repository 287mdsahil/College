#include <bits/stdc++.h>
using namespace std;
class Wallet
{
	int id;
	float amount;

  public:
	Wallet()
	{
		id = 0;
		amount = 0;
	}
	void enter_id()
	{
		cout << "\nEnter id :";
		cin >> id;
		cin.ignore();
	}
	void update_amt()
	{
		float rp; // = 250;
		cout << "\nEnter amount to top up :";
		cin >> rp;
		cin.ignore();
		amount += rp;
	}
	float ret_amount()
	{
		//cout<<"\nAmount Left"<<endl;
		return amount;
	}
	bool check_id(int o)
	{
		if (o == id)
			return true;
		else
			return false;
	}
	void update_trans(float am)
	{
		amount = amount - am;
	}
};
template <class T, class U>
class BILL
{
	string carno;
	string date;
	U amount;

  public:
	void randvehicle()
	{
		for (int i = 0; i < 8; i++)
		{
			if (i < 6)
			{
				if (i == 2 || i == 3)
					cout << char(rand() % 9 + '0');
				else
					cout << char(rand() % 26 + 'A');
			}
			else
				cout << char(rand() % 10 + '0');
		}
		time_t tt;
		struct tm *ti;
		time(&tt);
		ti = localtime(&tt);
		date = asctime(ti);
	}
	void datedisp()
	{
		cout << date << endl;
	}
};
template <class T, class U>
class TOLLTAX
{
  protected:
	T nocar;
	T way;
	U totalfare;
	U tax[2][3];
	T twoW;
	T threeW;
	T fourW;
	U prepaid;
	U instant;
	//Wallet w[100];
	int count;

  public:
	TOLLTAX()
	{
		nocar = 0;
		totalfare = 0;
		twoW = 0;
		threeW = 0;
		fourW = 0;
		prepaid = 0;
		instant = 0;
		count = 0;
		tax[0][0] = 10;
		tax[0][1] = 8;
		tax[0][2] = 12;
		tax[1][0] = 10;
		tax[1][1] = 20;
		tax[1][2] = 18;
	}
	void update_tax();
	void receiveToll(Wallet w[]);
	void displayCar();
	void displayAmt();
	void prepaid_wallet(int a, int b, Wallet w[])
	{
		int e = a;
		int c = b;
		if (count == 0)
		{
			cout<< "Creating new account !"<<endl;
			//count++;
			w[count].enter_id();
			w[count].update_amt();
			prepaid = prepaid + e * tax[e - 1][c - 1];
			//cout<<"lol\n";
			w[count].update_trans(e * tax[e - 1][c - 1]);
			//cout<<"lol\n";
			cout << "\nAmount left=";
			cout << w[count].ret_amount();
			count++;
			return;
		}
		cout << "\nEnter ID :";
		int id;
		cin >> id;
		cin.ignore();
		int flag = 0;
		//cout<<count<<" huha"<<endl;
		for (int i = 0; i < count; i++)
		{
			//flag=0;
			if (w[i].check_id(id) == true)
			{
				//cout<<w[i].ret_amount();
				if ((e * tax[e - 1][c - 1]) > w[i].ret_amount())
				{
					cout << "required amount :" << e * tax[e - 1][c - 1] << endl;
					cout << "available amount :" << w[i].ret_amount();
					cout << "\nNot enough money !" << endl;
					//	cout<<"Enter money to top up"<<endl;
					w[i].update_amt();
				}
				prepaid = prepaid + e * tax[e - 1][c - 1];
				//cout<<"lol\n";
				cout << "\nAmount in wallet=" << w[i].ret_amount();
				w[i].update_trans(e * tax[e - 1][c - 1]);
				cout << "\nAmount left=" << w[i].ret_amount();

				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nID not found." << endl;
			cout<< "Creating new account !"<<endl;
			//count++;
			w[count].enter_id();
			w[count].update_amt();
			prepaid = prepaid + e * tax[e - 1][c - 1];
			//cout<<"lol\n";
			w[count].update_trans(e * tax[e - 1][c - 1]);
			//cout<<"lol\n";
			cout << "\nAmount left=";
			cout << w[count].ret_amount();
			count++;
		}
	}
	friend void randvehicle();
};

template <class T, class U>
void TOLLTAX<T, U>::update_tax()
{
	cout << "\nTo enter new tax rates choose wheeles" << endl;
	cout << "1. 2 Wheeler\n2. 4 Wheeler \n3. 8 Wheeler" << endl;
	int choice;
	cout << "Enter choice :";
	cin >> choice;
	cin.ignore();
	if (choice == 1)
	{
		cout << "Enter new tax rates:" << endl;
		cout << "1.Prepaid 2.Instant" << endl;
		int choice2;
		cout << "Enter choice :";
		cin >> choice2;
		cin.ignore();
		cout << "Enter amount: ";
		if (choice2 == 1)
		{
			cin >> tax[0][0];
			cin.ignore();
		}
		if (choice2 == 2)
		{
			cin >> tax[0][1];
			cin.ignore();
		}
	}
	else if (choice == 2)
	{
		cout << "Enter new tax rates:" << endl;
		cout << "1.Prepaid 2.Instant" << endl;
		int choice2;
		cin >> choice2;
		cin.ignore();
		cout << "Enter amount: ";
		if (choice2 == 1)
		{
			cin >> tax[1][0];
			cin.ignore();
		}
		if (choice2 == 2)
		{
			cin >> tax[1][1];
			cin.ignore();
		}
	}
	else if (choice == 3)
	{
		cout << "Enter new tax rates:" << endl;
		cout << "1.Prepaid 2.Instant" << endl;
		int choice2;
		cout << "Enter choice :";
		cin >> choice2;
		cin.ignore();
		cout << "Enter amount: ";
		if (choice2 == 1)
		{
			cin >> tax[2][0];
			cin.ignore();
		}
		if (choice2 == 2)
		{
			cin >> tax[2][1];
			cin.ignore();
		}
	}
	else
		cout << "\nWrong input" << endl;
}

template <class T, class U>
void TOLLTAX<T, U>::receiveToll(Wallet w[])
{
	int c, d, e;
	cout << "\nEnter no. of wheels:";
	cout << "\n1. 2 Wheeler\n2. 4 Wheeler\n3. 8 Wheeler\n";
	cout << "Enter choice :";
	cin >> c;
	cin.ignore();
	cout << "\n1. One-way\n2. Two-way\n";
	cout << "Enter choice :";
	cin >> e;
	cin.ignore();
	if (c > 3 || e > 2)
	{
		cout << "\nWrong input.";
		return;
	}
	nocar++;
	cout << "\nEnter method of payment";
	cout << "\n1. Prepaid wallet\n2. Instant payment\n";
	cout << "Enter choice :";
	cin >> d;
	cin.ignore();
	totalfare = totalfare + e * tax[e - 1][c - 1];
	if (d == 1)
	{
		prepaid_wallet(e, c, w);
	}
	else
		instant = instant + e * tax[e - 1][c - 1];
	if (c == 1)
		twoW++;
	else if (c == 2)
		threeW++;
	else
		fourW++;
	//cout<<"\n-------------BILL-------------\n";
	BILL<int, float> B;
	cout << endl;
	cout << "Bill Number:";
	B.randvehicle();
	cout << "\nAmount to be paid:" << e * tax[e - 1][c - 1];
	if (d == 1)
		cout << "\nPrepaid";
	else
		cout << "\nInstant";
	if (e == 1)
		cout << "\nOne-way";
	else
		cout << "\nTwo-way";
	cout << "\nTime:";
	B.datedisp();
	cout << "\nValid for 1 trip\n";
	//cout<<"\n------------------------------\n";
}
template <class T, class U>
void TOLLTAX<T, U>::displayCar()
{
	cout << "\n2 Wheeler:" << twoW;
	cout << "\n4 Wheeler:" << threeW;
	cout << "\n8 Wheeler:" << fourW;
	cout << "\nTotal cars:" << nocar;
}
template <class T, class U>
void TOLLTAX<T, U>::displayAmt()
{
	cout << "\nPrepaid:" << prepaid;
	cout << "\nInstant:" << instant;
	cout << "\nTotal Amount:" << totalfare;
}
int main()
{
	srand(time(NULL));
	TOLLTAX<int, float> T;
	Wallet w[100];
	while (1)
	{
		system("clear");
		int c;
		cout << "-----------TOLLTAX------------" << endl;
		cout << "1. Receive Toll\n2. Display no. of cars\n3. Display Amount\n4. Update toll tax \n5. Exit\n";
		cout << "Enter Choice:";
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1:
			T.receiveToll(w);
			getchar();
			break;
		case 2:
			T.displayCar();
			getchar();
			break;
		case 3:
			T.displayAmt();
			getchar();
			break;
		case 4:
			T.update_tax();
			//getchar();
			break;
		case 5:
			return 0;
		default:
			cout << "Invalid input !" << endl;
			getchar();
			break;
		}
	}
	return 0;
}
