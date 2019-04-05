#include <iostream>
#include <cstring>

using namespace std;
class TRANSACTION
{
	char *acc_num;
	int amount;
	int month, year, day;
	int type;

  public:
	void getdata(void)
	{
		acc_num = new char[12];
		cout << "Enter the Acount Number: ";
		cin >> acc_num;
		cin.ignore();
		cout << "Enter the Transaction Type:(1.withdrawal/2.deposit)\n=>";
		cin >> type;
		cin.ignore();
		cout << "Enter the Amount: ";
		cin >> amount;
		cin.ignore();
	}
	int return_day(void) { return day; }
	int return_month(void) { return month; }
	int return_year(void) { return year; }
	int return_amount(void) { return amount; }
	char *return_accnum(void) { return acc_num; }
	int return_type(void) { return type; }

	void refres(void)
	{
		time_t t = time(NULL);
		tm *timePtr = localtime(&t);
		day = (int)timePtr->tm_mday;
		month = (int)(timePtr->tm_mon) + 1;
		year = (int)(timePtr->tm_year) + 1900;
	}

	void show()
	{
		cout << "------------------------" << endl;
		if (type == 1)
			cout << "Type: Withdrawl" << endl;
		else
			cout << "Type: Deposit" << endl;
		cout << "amount :" << amount << endl;
		cout << "Date :" << day << ":" << month << ":" << year << endl;
		cout << endl;
	}
};

class BLANCE
{
	char acnt_num[21];
	int blance;
	int month, year, day;
	TRANSACTION t[100];
	int tcount;

  public:
	BLANCE()
	{
		tcount = 0;
	}

	void get(void)
	{
		//acnt_num = new char[12];
		cout << "Enter the Acount Number: ";
		cin >> acnt_num;
		cin.ignore();
		cout << "Enter the Amount: ";
		cin >> blance;
		cin.ignore();
		time_t t = time(NULL);
		tm *timePtr = localtime(&t);
		day = (int)timePtr->tm_mday;
		month = (int)(timePtr->tm_mon) + 1;
		year = (int)(timePtr->tm_year) + 1900;
	}

	int return_blance(void) { return blance; }

	void display(void)
	{
		cout << "\n===================================================\n";
		cout << "\nAccount Number: " << acnt_num << endl;
		cout << "Balance: " << blance << endl;
		cout << "Last Update: " << day << ":" << month << ":" << year << endl;
		cout << "\n===================================================\n";
	}
	char* returnactno(void) { return acnt_num; }

	void updatedata(TRANSACTION tran)
	{
		if (tran.return_type() == 1)
		{
			blance = blance - tran.return_amount();
		}
		else
		{
			blance = blance + tran.return_amount();
		}
		t[tcount] = tran;
		tcount++;
		day = tran.return_day();
		month = tran.return_month();
		year = tran.return_year();
	}

	void showTrans()
	{
		for (int i = 0; i < tcount; i++)
			t[i].show();
	}
};

class blance_list
{
	BLANCE list[10];
	int count;

  public:
	blance_list()
	{
		count = 0;
	}
	int check_id(char c[21])
	{
		for (int i = 0; i <= count; i++)
		{
			if (strcmp(c, list[i].returnactno()) ==0)
			{
				return i;
			}
		}
		return -1;
	}
	void prepaird(void)
	{
		BLANCE t;
		t.get();
		if (check_id(t.returnactno()) >= 0)
		{
			cout << "The Account No can't be same.";
		}
		else
		{
			list[count] = t;
			count++;
		}
	}
	void update(void)
	{
		TRANSACTION tran;
		tran.getdata();
		if (check_id(tran.return_accnum()) >= 0)
		{
			int n = check_id(tran.return_accnum());
			if ((list[n].return_blance() < tran.return_amount()) && tran.return_type() == 1)
			{
				cout << "Transaction Faild.";
			}
			else
			{
				tran.refres();
				list[n].updatedata(tran);
			}
		}
		else
		{
			cout << "Plase Enter A valid Account No.";
		}
	}
	void print(void)
	{
		char *act;
		act = new char[12];
		cout << "Enter The Account Number: ";
		cin >> act;
		cin.ignore();
		if (check_id(act) >= 0)
		{
			int n = check_id(act);
			list[n].display();
		}
		else
		{
			cout << "Please Enter A valid Account No.";
		}
	}

	void printAll(void)
	{
		for (int i = 0; i < count; i++)
		{
			list[i].display();
		}
	}

	void showTrans()
	{
		char *act;
		act = new char[12];
		cout << "Enter The Account Number: ";
		cin >> act;
		cin.ignore();
		if (check_id(act) >= 0)
		{
			int n = check_id(act);
			list[n].showTrans();
		}
		else
		{
			cout << "Please Enter A valid Account No.";
		}
	}
};

int main(void)
{
	blance_list b;
	int opt;
	while (1)
	{
		system("clear");
		cout << "\n--------------------------------------------------------\n";
		cout << "Chose An Option";
		cout << "\n---------------------------------------------------------\n";
		cout << "1.Enter New Details\n2.Make a Transaction\n3.Display Details of an Account\n4.Transactions of an account\n5.Print all account details\n6.Exit\nEnter choice :";
		cin >> opt;
		cin.ignore();
		switch (opt)
		{
		case 1:
			b.prepaird();
			//getchar();
			break;
		case 2:
			b.update();
			getchar();
			break;
		case 3:
			b.print();
			getchar();
			break;
		case 4:
			b.showTrans();
			getchar();
			break;
		case 5:
			b.printAll();
			getchar();
			break;
		case 6:
			exit(0);
		default:
			cout << "Plase Enter A valid Option\n";
			getchar();
			break;
		}
	}
}
