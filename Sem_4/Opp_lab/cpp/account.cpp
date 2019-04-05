#include <bits/stdc++.h>
using namespace std;
class account
{
    char type[2][10];
    char t_type[2][10];

  public:
    account()
    {
        strcpy(type[0], "SAVING");
        strcpy(type[1], "CURRENT");
        strcpy(t_type[0], "DEPOSIT");
        strcpy(t_type[1], "WITHDRAW");
    }
    void add2file(int, int, float);
};

void account::add2file(int c, int d, float x)
{
    ofstream fout;
    fout.open("account.txt", ios::out | ios::app);
    fout << type[c - 1] << " " << t_type[d - 1] << " " << x << "\n";
    fout.close();
}

class saving
{
  public:
    void deposit(float);
    void withdraw(float);
    static float balance;
};

float saving::balance = 0.0;
void saving::deposit(float x)
{
    if (x < 500)
    {
        cout << "\nMINIMUM DEPOSIT OF 500\n";
        return;
    }
    saving::balance = saving::balance + x;
    cout << "\nSAVING BALANCE:" << saving::balance;
}
void saving::withdraw(float x)
{
    if (saving::balance - x < 500)
    {
        cout << "\nMINIMUM BALANCE 500 SHOULD BE THERE TO WITHDRAW THE AMOUNT YOU REQUESTED\n";
        return;
    }
    saving::balance = saving::balance - x;
    cout << "\nSAVING BALANCE:" << saving::balance;
}
class current
{
  public:
    void deposit(float);
    void withdraw(float);
    static float balance;
};
float current::balance = 0.0;
void current::deposit(float x)
{
    if (x > 20000)
    {
        cout << "\nOVERDRAFT LIMIT 20000\n";
        return;
    }
    current::balance = current::balance + x;
    cout << "\nCURRENT BALANCE:" << current::balance;
}
void current::withdraw(float x)
{
    if (x - current::balance > 20000)
    {
        cout << "\nOVERDRAFT LIMIT 20000\n";
        return;
    }
    if (x < current::balance)
    {
        cout << "\nINSUFFICIENT BALANCE";
        return;
    }
    current::balance = current::balance - x;
    cout << "\nCURRENT BALANCE:" << current::balance;
}
int main()
{
    account A;
    while (1)
    {
        int c, d;
        float f;
        cout << "\n1. WITHDRAW AMOUNT\n2. DEPOSIT AMOUNT\n";
        cin >> c;
        if (c == 1)
        {
            cout << "\n1. SAVING ACCOUNT\n2. CURRENT ACCOUNT\n";
            cin >> d;
            if (d == 1)
            {
                cout << "\nSAVING BALANCE:" << saving::balance;
                saving s;
                cout << "\nENTER AMOUNT TO WITHDRAW:";
                cin >> f;
                if (f < 0)
                {
                    cout << "INVALID TRANSACTION\n";
                    continue;
                }
                s.withdraw(f);
            }
            else
            {
                current c;
                cout << "\nCURRENT BALANCE:" << current::balance;
                cout << "\nENTER AMOUNT TO WITHDRAW:";
                cin >> f;
                if (f < 0)
                {
                    cout << "INVALID TRANSACTION\n";
                    continue;
                }
                c.withdraw(f);
            }
        }
        else if (c == 2)
        {
            cout << "\n1. SAVING\n2. CURRENT\n";
            cin >> d;
            if (d == 1)
            {
                saving s;
                cout << "\nSAVING BALANCE:" << saving::balance;
                cout << "\nENTER AMOUNT TO DEPOSIT:";
                cin >> f;
                if (f < 0)
                {
                    cout << "INVALID TRANSACTION\n";
                    continue;
                }
                s.deposit(f);
            }
            else
            {
                current c;
                cout << "\nCURRENT BALANCE:" << current::balance;
                float f;
                cout << "\nENTER AMOUNT TO DEPOSIT:";
                cin >> f;
                if (f < 0)
                {
                    cout << "INVALID TRANSACTION\n";
                    continue;
                }
                c.deposit(f);
            }
        }
        else
            break;
        A.add2file(c, d, f);
    }
    return 0;
}
