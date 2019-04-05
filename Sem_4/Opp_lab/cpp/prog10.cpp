#include <bits/stdc++.h>
using namespace std;

class Person
{
	char holder_name[50];
	long int acc_number;
	//long int ifsc_code;
  public:
	void setname(char name[])
	{
		strcpy(holder_name, name);
	}

	void setAccountNumber(long int n)
	{
		acc_number = n;
	}

	string getname()
	{
		return holder_name;
	}

	long int getAccNo()
	{
		return acc_number;
	}
};

class Savings : public Person
{
	float amt;

  public:
	Savings()
	{
		amt = 0;
	}

	void initialize(float amt_todeposit)
	{
		if (amt_todeposit > 500)
			amt = amt_todeposit;
		else
		{
			cout << "Should maintain min balance of 500" << endl
				 << "Enter amount Again!" << endl;
			float amt_depo;
			cin >> amt_depo;
			initialize(amt_depo);
		}
	}

	void deposit(float amt)
	{
		if (amt < 0)
			cout << "Wrong Input" << endl
				 << endl;
		else
		{
			this->amt += amt;
			cout << "Deposit : " << amt << " to SAVINGS bank account SUCCESSFULL!!" << endl;
			cout << "BALANCE : " << this->amt << endl
				 << endl;
		}
	}

	void withdrawal(float amt)
	{
		if (amt < 0)
			cout << "Wrong Input" << endl
				 << endl;
		else
		{
			float chk = this->amt - amt;
			if (chk < 500)
			{
				cout << "BALANCE : " << this->amt << endl;
				cout << "Transaction NOT POSSIBLE\nShould maintain the minimum balance" << endl
					 << endl;
			}
			else if (chk >= 500)
			{
				this->amt = chk;
				cout << "Withdrawal : " << amt << " from SAVINGS bank account SUCCESSFULL!!" << endl;
				cout << "BALANCE : " << this->amt << endl
					 << endl;
			}
		}
	}

	float getamt()
	{
		return amt;
	}
};

class Current : public Person
{
	float amt;
	float od_util; //Overdraft limit is 20000
  public:
	Current()
	{
		od_util = 0;
	}
	void initialize(float amt_todeposit)
	{
		amt = amt_todeposit;
	}

	void deposit(float amt)
	{
		if (amt < 0)
			cout << "Wrong Input" << endl;
		else
		{
			if (od_util == 0)
			{
				this->amt += amt;
				cout << "Deposit : " << amt << " to CURRENT bank account SUCCESSFULL!!" << endl;
				cout << "BALANCE : " << this->amt << " Credit(CR)" << endl;
				cout << "OVERDRAFT utilized : " << od_util << endl
					 << endl;
			}
			else
			{
				if (amt >= od_util)
				{
					this->amt = amt - od_util;
					od_util = 0;
					cout << "Deposit : " << amt << " to CURRENT bank account SUCCESSFULL!!" << endl;
					cout << "BALANCE : " << this->amt << " Credit(CR)" << endl;
					cout << "OVERDRAFT utilized : " << od_util << endl
						 << endl;
				}
				else
				{
					od_util = od_util - amt;
					this->amt = -(od_util);
					cout << "Deposit : " << amt << " to CURRENT bank account SUCCESSFULL!!" << endl;
					cout << "BALANCE : " << od_util << " Debit(DR)" << endl;
					cout << "OVERDRAFT utilized : " << od_util << endl
						 << endl;
				}
			}
		}
	}

	void withdrawal(float amt)
	{
		if (amt < 0)
			cout << "Wrong Input" << endl;
		else
		{
			if (od_util == 0)
			{
				if (this->amt >= amt)
				{
					this->amt = this->amt - amt;
					cout << "Withdrawal : " << amt << " from CURRENT bank account SUCCESSFULL!!" << endl;
					cout << "BALANCE : " << this->amt << " Credit(CR)" << endl;
					cout << "OVERDRAFT utilized : " << od_util << endl
						 << endl;
				}
				else
				{
					if (abs(this->amt - amt) > 20000)
					{
						cout << "Transaction NOT POSSIBLE\nOVERDRAFT LIMIT is 20000" << endl;
						cout << "BALANCE : " << this->amt << " Debit(DR)" << endl;
						cout << "OVERDRAFT utilized : " << od_util << endl
							 << endl;
					}

					else
					{
						this->amt = this->amt - amt;
						od_util = -(this->amt);
						cout << "Withdrawal : " << amt << " from CURRENT bank account SUCCESSFULL!!" << endl;
						cout << "BALANCE : " << abs(this->amt) << " Debit(DR)" << endl;
						cout << "OVERDRAFT utilized : " << od_util << endl
							 << endl;
					}
				}
			}

			else
			{
				if (od_util + amt > 20000)
				{
					cout << "Transaction NOT POSSIBLE\nOVERDRAFT LIMIT is 20000" << endl;
					cout << "BALANCE : " << this->amt << " Debit(DR)" << endl;
					cout << "OVERDRAFT utilized : " << od_util << endl
						 << endl;
				}
				else
				{
					od_util = od_util + amt;
					this->amt = -(od_util);
					cout << "Withdrawal : " << amt << " from CURRENT bank account SUCCESSFULL!!" << endl;
					cout << "BALANCE : " << abs(this->amt) << " Debit(DR)" << endl;
					cout << "OVERDRAFT utilized : " << od_util << endl
						 << endl;
				}
			}
		}
	}

	float getamt()
	{
		return amt;
	}

	float getodutil()
	{
		return od_util;
	}
};

string date_update()
{
	string str;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	str = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
	return str;
}

string time_update()
{
	string str;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	str = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
	return str;
}

class AllTransaction
{
	unordered_set<long int> acc_no;
	vector<Savings> save;
	vector<Current> cur;

  private:
	long int generate()
	{
		long int myRand;
		srand(unsigned(time(0)));
		const long int MAX = 99999999999;
		const long int MIN = 10000000000;
		for (int i = 0; i < 12; i++)
		{
			myRand = rand() / (float)RAND_MAX * (MAX - MIN) + MIN;
		}
		if (acc_no.empty())
			acc_no.insert(myRand);

		else
		{
			if (acc_no.find(myRand) == acc_no.end())
				acc_no.insert(myRand);
			else
				generate();
		}
		return myRand;
	}

  public:
	AllTransaction()
	{
		ifstream I_sav("Savings_account_database.dat", ios::in | ios::binary);
		ifstream I_cur("Current_account_database.dat", ios::in | ios::binary);

		if (I_sav.good())
		{
			Savings sav;
			while (I_sav.read((char *)&sav, sizeof(sav)))
			{
				save.push_back(sav);
				acc_no.insert(sav.getAccNo());
			}
		}
		else
		{
			//cout << "Initialising Savings Database" << endl;
		}

		if (I_cur.good())
		{
			Current s;
			while (I_cur.read((char *)&s, sizeof(s)))
			{
				cur.push_back(s);
				acc_no.insert(s.getAccNo());
			}
		}
		else
		{
			//cout << "Initialising Current Database" << endl;
		}
	}

	void add_member()
	{
		char sname[50];
		long int new_acc_no;
		cout << "Enter name : ";
		cin >> sname;
		cin.ignore();
		new_acc_no = generate();
		cout << "1.To Create savings account" << endl;
		cout << "2.To Create current account" << endl;
		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == 1)
		{
			Savings p;
			p.setname(sname);
			p.setAccountNumber(new_acc_no);
			save.push_back(p);
			cout << "Your ACCOUNT No. is : " << p.getAccNo() << endl;
		}
		if (choice == 2)
		{
			Current p;
			p.setname(sname);
			p.setAccountNumber(new_acc_no);
			cur.push_back(p);
			cout << "Your ACCOUNT No. is : " << p.getAccNo() << endl;
		}
		cout << "ACCOUNT ADDED" << endl;
	}

	void transaction()
	{
		long int input_acc;
		cout << "Enter ACCOUNT NUMBER : ";
		cin >> input_acc;
		if (acc_no.find(input_acc) == acc_no.end())
		{
			cout << "INVALID ACCOUNT NUMBER" << endl;
			cout << "TRY AGAIN" << endl
				 << endl;
			transaction();
		}
		else
		{
			fstream otransaction("Transactdatabase.txt", ios::out | ios::app);
			string s;
			cout << "ACCOUNT FOUND" << endl
				 << endl;
			cout << "1.SAVINGS" << endl;
			cout << "2.CURRENT" << endl;
			cout << "Enter TYPE of ACCOUNT : ";
			int ch, index;
			cin >> ch;
			cout << "Confirm with ACCOUNT HOLDER'S name : ";
			cin >> s;
			int flag = 0;
			if (ch == 1)
			{
				for (int i = 0; i < save.size(); i++)
				{
					if (s == save[i].getname())
					{
						flag = 1;
						index = i;
						break;
					}
				}
				if (flag == 1)
				{
					cout << "WELCOME " << s << endl
						 << endl;
					cout << "Is it your first time in the bank?(y/n)" << endl;
					char ans;
					cin >> ans;
					if (ans == 'y' || ans == 'Y')
					{
						cout << "Enter Amount to Deposit" << endl;
						float amt;
						cin >> amt;
						save[index].initialize(amt);
						otransaction << save[index].getname() << "\t\t" << save[index].getAccNo() << "\t\t" << save[index].getamt() << "\t\t"
									 << "DEPOSIT\t" << date_update() << "\t" << time_update() << endl;
					}
					else
					{
						cout << "1.DEPOSIT\n2.WITHDRAWAL\n3.BALANCE" << endl;
						int x;
						cin >> x;
						if (x == 1)
						{
							cout << "Enter Amount to deposit" << endl;
							float amount;
							cin >> amount;
							save[index].deposit(amount);
							otransaction << save[index].getname() << "\t\t" << save[index].getAccNo() << "\t\t" << save[index].getamt() << "\t\t"
										 << "DEPOSIT\t" << date_update() << "\t" << time_update() << endl;
						}
						else if (x == 2)
						{
							cout << "Enter Amount to Withdraw" << endl;
							float amount;
							cin >> amount;
							save[index].withdrawal(amount);
							otransaction << save[index].getname() << "\t\t" << save[index].getAccNo() << "\t\t" << save[index].getamt() << "\t\t"
										 << "WITHDRAW\t" << date_update() << "\t" << time_update() << endl;
						}
						else if (x == 3)
						{
							cout << "YOUR BALANCE is : " << save[index].getamt() << endl
								 << endl;
						}
					}
				}
				else
					cout << "ACCOUNT HOLDER'S name NOT matching" << endl;
				//File writing
				ofstream o_bin("Savings_account_database.dat", ios::binary);
				ofstream o_txt("Savings_account_database.txt", ios::out | ios::trunc);
				o_txt << "NAME\t\tACCOUNT NO.\t\tBALANCE\n";
				for (int i = 0; i < save.size(); i++)
				{
					o_bin.write((char *)&save[i], sizeof(save[i]));
					o_txt << save[i].getname() << "\t\t" << save[i].getAccNo() << "\t\t" << save[i].getamt() << endl;
				}
				o_bin.close();
				o_txt.close();
			}

			else if (ch == 2)
			{
				for (int i = 0; i < cur.size(); i++)
				{
					if (s == cur[i].getname())
					{
						flag = 1;
						index = i;
						break;
					}
				}
				if (flag == 1)
				{
					cout << "WELCOME " << s << endl
						 << endl;
					cout << "Is it your first time in the bank?(y/n)" << endl;
					char ans;
					cin >> ans;
					if (ans == 'y' || ans == 'Y')
					{
						cout << "Enter Amount to Deposit" << endl;
						float amt;
						cin >> amt;
						cur[index].initialize(amt);
						otransaction << save[index].getname() << "\t\t" << save[index].getAccNo() << "\t\t" << save[index].getamt() << "\t\t"
									 << "DEPOSIT\t" << date_update() << "\t" << time_update() << endl;
					}
					else
					{
						cout << "1.DEPOSIT\n2.WITHDRAWAL\n3.BALANCE" << endl;
						int x;
						cin >> x;
						if (x == 1)
						{
							cout << "Enter Amount to deposit" << endl;
							float amount;
							cin >> amount;
							cur[index].deposit(amount);
							otransaction << cur[index].getname() << "\t\t" << cur[index].getAccNo() << "\t\t" << cur[index].getamt() << "\t\t"
										 << "DEPOSIT\t" << date_update() << "\t" << time_update() << endl;
						}
						else if (x == 2)
						{
							cout << "Enter Amount to Withdraw" << endl;
							float amount;
							cin >> amount;
							cur[index].withdrawal(amount);
							otransaction << cur[index].getname() << "\t\t" << cur[index].getAccNo() << "\t\t" << cur[index].getamt() << "\t\t"
										 << "WITHDRAW\t" << date_update() << "\t" << time_update() << endl;
						}
						else if (x == 3)
						{
							cout << "YOUR BALANCE is : " << cur[index].getamt() << endl;
							cout << "Overdraft Utilised : " << cur[index].getodutil() << endl
								 << endl;
						}
					}
				}
				else
					cout << "ACCOUNT HOLDER'S name NOT matching" << endl;
				//File writing
				ofstream o_bin("Current_account_database.dat", ios::binary);
				ofstream o_txt("Current_account_database.txt", ios::out | ios::trunc);
				o_txt << "NAME\t\tACCOUNT NO.\t\tBALANCE\t\tOverdraft Utilised\n";
				for (int i = 0; i < cur.size(); i++)
				{
					o_bin.write((char *)&cur[i], sizeof(save[i]));
					o_txt << cur[i].getname() << "\t\t" << cur[i].getAccNo() << "\t\t" << cur[i].getamt() << "\t\t" << cur[i].getodutil() << endl;
				}
				o_bin.close();
				o_txt.close();
			}
		}
	}
};

int main()
{
	AllTransaction at;
	while (1)
	{
		system("clear");
		int k1;
		cout << "1.Add account" << endl;
		cout << "2.Account handling" << endl;
		cout << "3. Exit" << endl;
		cout<<"Enter choice :";
		cin >> k1;
		cin.ignore();

		switch (k1)
		{
		case 1:
			at.add_member();
			getchar();
			break;
		case 2:
			at.transaction();
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
	return 0;
}
