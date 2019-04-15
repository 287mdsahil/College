#include <iostream>
#include "String.hpp"
using namespace std;
using namespace StringNamespace;

void menu()
{
    while (1)
    {
        system("clear");
        cout << "MENU:" << endl;
        cout << "1.Assign one object with another" << endl;
        cout << "2.Concatinate two strings" << endl;
        cout << "3.Compare two strings" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {

        case 1:
        {
            cout << "Enter the string : ";
            char c[100];
            cin >> c;
            cin.ignore();
            String obj1(c);
            cout << "First object : ";
            obj1.show();
            cout << endl;
            String obj2 = obj1;
            cout << "Second object : ";
            obj2.show();
            getchar();
            break;
        }

        case 2:
        {
            cout << "Enter the first string : ";
            char c1[100];
            cin >> c1;
            cin.ignore();
            cout << "Enter the second string : ";
            char c2[100];
            cin >> c2;
            cin.ignore();
            String s1(c1), s2(c2);
            String s3 = s1 + s2;
            cout << "Concatinated string : ";
            s3.show();
            getchar();
            break;
        }

        case 3:
        {
            char c1[100], c2[100];
            cout << "Enter the first string : ";
            cin >> c1;
            cin.ignore();
            cout << "Enter the second string : ";
            cin >> c2;
            cin.ignore();
            String s1(c1), s2(c2);

            int flag = 1;
            while (flag)
            {
                cout << "\nMenu:" << endl;
                cout << "1. use < operator" << endl;
                cout << "2. use <= operator" << endl;
                cout << "3. use > operator" << endl;
                cout << "4. use >= operator" << endl;
                cout << "5.Exit" << endl;
                cout << "Enter choice : ";
                int x;
                cin >> x;
                cin.ignore();

                switch (x)
                {

                case 1:
                {
                    if (s1 < s2)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    getchar();
                    break;
                }

                case 2:
                {
                    if (s1 <= s2)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    getchar();
                    break;
                }

                case 3:
                {
                    if (s1 > s2)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    getchar();
                    break;
                }

                case 4:
                {
                    if (s1 >= s2)
                        cout << "true" << endl;
                    else
                        cout << "false" << endl;
                    getchar();
                    break;
                }

                case 5:
                {
                    flag = 0;
                    break;
                }
                default:
                    cout << "Invalid input";
                    getchar();
                    break;
                }
            }
            break;
        }

        case 4:
        {
            return;
        }

        default:
            cout << "Invalid entry" << endl;
            getchar();
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}