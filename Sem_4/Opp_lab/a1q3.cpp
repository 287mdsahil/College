#include<iostream>
#include<string>
using namespace std;


class item
{
    string code;
    string name;
    int quantity;
    float rate;
    
    public:
    
    void getItem()
    {
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

    void showItem()
    {
        cout<<"Item code:\t"<<code<<endl;
        cout<<"Item name:\t"<<name<<endl;
        cout<<"Item quantity:\t"<quantity<<endl;
        cout<<"Item rate:\t"<<rate<<endl;
        return;
    }

    void setPrice(float p)
    {
        rate = p;
        return;
    }

    int setQuantity(int q)
    {
        quantity = p;
        return;
    }

    string getCode()
    {
        return code;
    }

    string getName()
    {
        return name;
    }

    float getRate()
    {
        return rate;
    }

    int getQuantity()
    {
        return quantity;
    }

}

int main()
{
    return 0;
}