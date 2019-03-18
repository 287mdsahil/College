#include <bits/stdc++.h>
using namespace std;

template <class T, class U>
class BILL
{
	string carno;
	string date;
	U amount;

  public:
	void randvehicle()
	{
		for (int i = 0; i < 10; i++)
		{
			if (i < 6)
			{
				if (i == 2 || i == 3)
					cout << char(rand() % 10 + '0');
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
		tax[0][0] = 60;
		tax[0][1] = 80;
		tax[0][2] = 100;
		tax[1][0] = 110;
		tax[1][1] = 145;
		tax[1][2] = 180;
	}

	friend void randvehicle();

	void displayCar()
	{
		cout << "\nTWO WHEELER:" << twoW;
		cout << "\nTHREE WHEELER:" << threeW;//cout<<"\n------------------------------\n";
		cout << "\nFOUR WHEELER:" << fourW;
		cout << "\nTOTAL CARS:" << nocar;
		getchar();
	}

	void displayAmt()
	{
		cout << "\nPREPAID:" << prepaid;
		cout << "\nINSTANT:" << instant;
		cout << "\nTOTAL AMOUNT:" << totalfare;
		getchar();
	}

	void receiveToll()
	{
		int c, d, e;
		cout << "\nENTER CAR TYPE:";
		cout << "\n1.TWO WHEELER\n2.THREE WHEELER\n3.FOUR WHEELER\nEnter choice : ";
		cin >> c;
		cin.ignore();
		if (c > 3)
		{
			cout << "Invalid input !";
			getchar();
			return;
		}
		cout << "\n1.ONE-WAY\n2. RETURN\nEnter choice : ";
		cin >> e;
		cin.ignore();
		if (e > 2)
		{
			cout << "Invalid input !";
			getchar();
			return;
		}
		nocar++;
		cout << "\nENTER PAYMENT METHOD:";
		cout << "\n1. PREPAID\n2. INSTANT\nEnter choice : ";
		cin >> d;
		cin.ignore();
		totalfare = totalfare + tax[e - 1][c - 1];
		if (d == 1)
			prepaid = prepaid + tax[e - 1][c - 1];
		else
			instant = instant + tax[e - 1][c - 1];
		if (c == 1)
			twoW++;
		else if (c == 2)
			threeW++;
		else
			fourW++;
		cout << "\nBILL\n";
		BILL<int, float> B;
		cout << "\nVEHICLE NO:";
		B.randvehicle();
		cout << "\nAMOUNT PAID:" << tax[e - 1][c - 1];
		if (d == 1)
			cout << "\tPREPAID";
		else
			cout << "\tINSTANT";
		if (e == 1)
			cout << "\nONE-WAY";
		else
			cout << "\nRETURN";
		cout << "\nTIME:";
		B.datedisp();
		//cout << "\nVALID FOR 24 HRS";
		getchar();
	}
};

int main()
{
	srand(time(NULL));
	TOLLTAX<int, float> T;
	while (1)
	{
		system("clear");
		int c;
		cout << "MENU:\n1. RECEIVE TOLL\n2. DISPLAY NO. OF CAR\n3. DISPLAY AMOUNT\n4. Exit"<<endl;
		cout << "ENTER CHOICE:";
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1:
			T.receiveToll();
			break;
		case 2:
			T.displayCar();
			break;
		case 3:
			T.displayAmt();
			getchar();
			break;

		case 4:
			return 0;
		default:
			cout << "Invalid input !" << endl;
			getchar();
			break;
		}
	}
	return 0;
}
