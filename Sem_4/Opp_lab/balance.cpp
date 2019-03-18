#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::setw;

enum class transactionType {
    debit,
    credit
};

class Date
{
    int d, m, y;
    
    public:
    Date() {
        setValues(0, 0, 0);
    }

    Date(int day, int month, int year) {
        setValues(day, month, year);
    }

    void setValues(int day, int month, int year) {
        d = day;
        m = month;
        y = year;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << date.d << "/" << std::setfill('0') << std::setw(2) << date.m << "/" << date.y;
        os << oss.str();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Date& date) {
        char temp;
        is >> date.d;
        is >> temp;

        if(temp != '/') {
            date.d = 0;
            while(is.get() != '\n');
            return is;
        }

        is >> date.m;
        is >> temp;

        if(temp != '/') {
            date.d = 0;
            date.m = 0;
            while(is.get() != '\n');
            return is;
        }

        is >> date.y;

        return is;
    }
};


class Balance
{
    friend class Transaction;
    std::string acNo;
    double bal;
    Date lstUpd;

    public:
    Balance() {
        setValues("", Date(), 0.0);
    }

    Balance(std::string accountNo, Date lastUpdate, double balance) {
        setValues(accountNo, lastUpdate, balance);
    }

    void setValues(std::string accountNo, Date lastUpdate, double balance) {
        acNo = accountNo;
        lstUpd = lastUpdate;
        bal = balance;
    }

    friend std::ostream& operator<<(std::ostream& os, const Balance& b) {
        os << setw(15) << b.acNo;
        os << setw(20) << b.lstUpd;
        os << setw(15) << std::fixed << std::setprecision(2) << b.bal;
    }

    void printPretty() {
        cout.setf(std::ios::left);
        cout << setw(15) << "Account No";
        cout << setw(20) << "Last Updated";
        cout << setw(15) << "Amount";
        cout << "\n";
        cout << (*this);
        cout << "\n";
        cout.unsetf(std::ios::left);
    }
};

class Transaction
{
    friend class Balance;
    std::string acNo;
    Date tranDate;
    transactionType typ;
    double amt;
    
    public:
    Transaction() : acNo(""), tranDate(0, 0, 0), typ(transactionType::credit), amt(0.0) {
    }
    
    bool transact(Balance& b, std::string accountNo, Date transactionDate, transactionType type, double transactionAmount) {
        if(b.acNo != accountNo) 
            return false;
        if(type == transactionType::debit) {
            if(b.bal < transactionAmount)
                return false;
            else {
                b.bal -= transactionAmount;
                acNo = accountNo;
                tranDate = transactionDate;
                typ = type;
                amt = transactionAmount;
                b.lstUpd = tranDate;
            }
        }
        else {
            b.bal += transactionAmount;
            acNo = accountNo;
            tranDate = transactionDate;
            typ = type;
            amt = transactionAmount;
            b.lstUpd = tranDate;
        }
        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const Transaction& t) {
        os << setw(15) << t.acNo;
        os << setw(20) << t.tranDate;
        os << setw(20);
        if(t.typ == transactionType::credit)
            os << "Credit";
        else
            os << "Debit";
        os << setw(15) << std::fixed << std::setprecision(2) << t.amt;
        return os;
    }

    void printPretty() {
        cout.setf(std::ios::left);
        cout << setw(15) << "Account No";
        cout << setw(20) << "Transaction Date";
        cout << setw(20) << "Transaction Type";
        cout << setw(15) << "Amount";
        cout << "\n";
        cout << (*this);
        cout << "\n";
        cout.unsetf(std::ios::left);
    }
};

int main()
{
    Balance b;
    std::string acNo;
    int choice;
    
    double bal; Date dat; transactionType tTyp; char temp;

    cout << "Create Balance Entry:\n";
    cout << "Account No: ";
    cin >> acNo;
    while(true) {
        cout << "Balance: ";
        cin >> bal;
        if(bal < 0)
            cout << "Balance Should be non-negative.\n";
        else
            break;
    }
    cout << "Creation Date: ";
    cin >> dat;
    b.setValues(acNo, dat, bal);

    cout << "1. Transact\n";
    cout << "2. Show Balance\n";
    cout << "3. Exit\n";

    while(true) {
        
        std::cout << "Enter choice: ";
        std::cin >> choice;
        getchar();
        
        switch(choice) {
            case 1: {
                        Transaction t;
                        cout << "Account No: " << acNo << "\n";
                        cout << "Transaction Date: "; cin >> dat;
                        while(true) {
                            cout << "Type(c/d): "; cin >> temp;
                            switch(temp) {
                                case 'c': tTyp = transactionType::credit; break;
                                case 'd': tTyp = transactionType::debit; break;
                                default: cout << "Wrong Transaction Type\n'c' for Credit, 'd' for Debit\n";
                            }
                            if(temp == 'c' || temp == 'd')
                                break;
                        }
                        while(true) {
                            cout << "Amount: ";
                            cin >> bal;
                            if(bal < 0)
                                cout << "Amount Should be non-negative.\n";
                            else
                                break;
                        }
                        if(t.transact(b, acNo, dat, tTyp, bal)) {
                            cout << "Transaction Successful!\n";
                            t.printPretty();
                        }
                        else {
                            cout << "Transaction FAILED!\n";
                        }
                    }
                    break;
            case 2: b.printPretty();
                    break;
            case 3: break;
            default:
                    std::cout << "Invalid Choice!\n";
        }
        
        if(choice == 3)
            break;
    
    }
    
    return 0;
}
