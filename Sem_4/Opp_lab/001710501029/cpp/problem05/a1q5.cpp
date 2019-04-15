#include<iostream>
#include<stdlib.h>
using namespace std;

template<class T>
class Array;

template<class T>
Array<T> operator+(Array<T> const &,Array<T> const &);
template<class T>
Array<T> operator *(Array<T> const &,T const c);
template<class T>
Array<T> operator *(T const c,Array<T> const &);

template <class T>
class Array{
    T* ptr;
    int n;

    public:
    Array(int k=0, T e=0){
        n=k;
        if(n<0){
            cout<<"Incorrect array size "<<n<<endl;
            exit(0);
        }
        else if(n>0){
            ptr = new T[n];
            for(int i=0;i<n;i++)
                ptr[i]=e;
        }
        else{
            ptr = NULL;
        }
    }

    Array(const Array<T> &a){
        n = a.n;
        if(n>0){
            ptr = new T[n];
            for(int i=0;i<n;i++){
                ptr[i]=a.ptr[i];
            }
        }
        else{
            ptr=NULL;
        }
    }

    Array(T *ar, int size){
        n=size;
        if(n<0){
            cout<<"Array size cannot be negative!"<<endl;
            exit(0);
        }
        else if(n>0){
            ptr = new T[n];
            for(int i=0;i<n;i++)
                ptr[i]=ar[i];
        }
        else{
            ptr = NULL;
        }
    }

    ~Array(){
        if(n>0)
            delete [] ptr;
        else
            delete ptr;
    }

    int size() const{
        return n;
    }

    T operator [](int i) const{
        return ptr[i];
    }

    T operator = (const Array<T> &a) {
        n=a.size();
        ptr = new T[n];
        for(int i=0;i<n;i++){
            ptr[i]=a[i];
        }
    }

    /*T operator [](int i){
        return ptr[i];
    }*/
    
    friend Array<T> operator +<>(Array<T> const &,Array<T> const &);
    friend Array<T> operator *<>(Array<T> const &,T const c);
    friend Array<T> operator *<>(T const c,Array<T> const &);
    
};

template<class T>
Array<T> operator+(Array<T> const &a1,Array<T> const &a2){
    if(a1.size()!=a2.size()){
        cout<<"Array size mismatch !"<<a1.size()<<" "<<a2.size()<<endl;
        exit(0);
    }
    else{
        T c[a1.size()];
        for(int i=0;i<a1.size();i++){
            c[i]=a1[i]+a2[i];
        }
        Array<T> b(c,a1.size());
        return b;
    }
}

template<class T>
Array<T> operator*(Array<T> const &a,T const c){
    T ar[a.size()];
        for(int i=0;i<a.size();i++){
            ar[i]=a[i]*c;
        }
        Array<T> b(ar,a.size());
        return b;
}

template<class T>
Array<T> operator*(T const c,Array<T> const &a){
    T ar[a.size()];
        for(int i=0;i<a.size();i++){
            ar[i]=a[i]*c;
        }
        Array<T> b(ar,a.size());
        return b;
}





int main(){
    while(1){
        system("clear");
        cout<<"MENU:"<<endl;
        cout<<"1.Add two objects"<<endl;
        cout<<"2.Assign one object by another"<<endl;
        cout<<"3.Iterating through Array elements"<<endl;
        cout<<"4.Multiplication with constant"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter choice: ";
        int choice;
        cin>>choice;
        cin.ignore();
        
        switch (choice)
        {
            case 1:{
                int n1,n2;
                cout<<"Enter the size of first array: ";
                cin>>n1;
                cin.ignore();
                cout<<"Enter the elements: ";
                int ar1[n1];
                for(int i=0;i<n1;i++)
                    cin>>ar1[i];
                cin.ignore();
                cout<<"Enter the size of second array: ";
                cin>>n2;
                cin.ignore();
                cout<<"Enter the elements: ";
                int ar2[n2];
                for(int i=0;i<n2;i++)
                    cin>>ar2[i];
                cin.ignore();
                Array<int> a1(ar1,n1);
                Array<int> a2(ar2,n2);
                Array<int> sum = a1+a2;
                cout<<endl<<"Resultant array: ";
                for(int i=0;i<sum.size();i++)
                    cout<<sum[i]<<" ";
                cout<<endl;
                getchar();
                break;
            }

            case 2:{
                int n;
                cout<<"Enter the size of array: ";
                cin>>n;
                cin.ignore();
                cout<<"Enter the elements: ";
                int ar[n];
                for(int i=0;i<n;i++)
                    cin>>ar[i];
                cin.ignore();
                Array<int> a1(ar,n);
                Array<int> a2(a1);
                cout<<endl<<"New assigned array: ";
                for(int i=0;i<a2.size();i++)
                    cout<<a2[i]<<" ";
                cout<<endl;
                getchar();
                break;
            }

            case 3:{
                int n;
                cout<<"Enter the size of array: ";
                cin>>n;
                cin.ignore();
                cout<<"Enter the elements: ";
                int ar[n];
                for(int i=0;i<n;i++)
                    cin>>ar[i];
                cin.ignore();
                Array<int> a(ar,n);
                cout<<endl;
                for(int i=0;i<a.size();i++)
                    cout<<"element "<<i+1<<" : "<<a[i]<<" "<<endl;
                getchar();
                break;
            }

            case 4:{
                int n;
                cout<<"Enter the size of array: ";
                cin>>n;
                cin.ignore();
                cout<<"Enter the elements: ";
                int ar[n];
                for(int i=0;i<n;i++)
                    cin>>ar[i];
                cin.ignore();
                cout<<"Enter the multiplier: ";
                int c;
                cin>>c;
                cin.ignore();
                Array<int> a(ar,n);
                Array<int> a1=a*c;
                Array<int> a2=c*a;
                cout<<endl<<"Array*"<<c<<": ";
                for(int i=0;i<a1.size();i++)
                    cout<<a1[i]<<" ";
                cout<<endl;
                cout<<endl<<c<<"*Array"<<": ";
                for(int i=0;i<a2.size();i++)
                    cout<<a2[i]<<" ";
                cout<<endl;
                getchar();
                break;
            }

            case 5:{
                return 0;
            }
            default:
                cout<<"Invalid entry"<<endl;
                getchar();
                break;
        }
    }
    return 0;
}