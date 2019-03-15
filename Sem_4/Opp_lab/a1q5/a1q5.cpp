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

    Array<int> a(5);
    Array<int> b(a);
    int c[]={1,2,3};
    Array<int> d(c,int(3));
    int e[]={2,3,4};
    Array<int> f(e,3);
    Array<int> g=d+f;
    for(int i=0 ;i<d.size();i++)
        cout<<g[i]<<" ";
    cout<<endl;
    Array<int> h;
    h=g*5 + 2*g;
    for(int i=0 ;i<d.size();i++)
        cout<<h[i]<<" ";
    cout<<endl;
    return 0;
}