#include <iostream>
using namespace std;
namespace StringNamespace
{
class String
{
    int size;
    char *ptr;
    int *count;

  public:
    String(int n = 0)
    {
        size = n;
        if (size > 0)
            ptr = new char[size];
        else
            ptr = NULL;
        count = new int(0);
        cout<<"ref count :"<<*count<<endl;
    }

    String(const char *s)
    {
        int n = 0;
        for (n = 0; s[n] != '\0'; n++)
            ;
        size = n;
        ptr = new char[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = s[i];
        }
        count = new int(0);
        cout<<"ref count :"<<*count<<endl;
    }

    String(const String &s)
    {
        size = s.size;
        ptr = new char[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = s.ptr[i];
        }
        count = s.count;
        *count=*count+1;
        cout<<"ref count :"<<*count<<endl;
    }

    ~String()
    {
        cout<<"destructor called\t";
        cout<<"Initial ref count :"<<*count<<"\t";
        if(*count==0)
        {
            delete[] ptr;
        }
        else
        {
            *count=*count-1;
        }
        cout<<"ref count :"<<*count<<endl;
    }

    void operator=(const char *s)
    {
        int n = 0;
        for (n = 0; s[n] != '\0'; n++)
            ;
        size = n;
        ptr = new char[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = s[i];
        }
    }

    int len()
    {
        return size;
    }

    void show()
    {
        for (int i = 0; i < size; i++)
            cout << ptr[i];
    }

    static int scmp(String &s1, String &s2)
    {
        if (s1.size == 0 && s2.size == 0)
            return 0;
        else if (s1.size == 0)
            return -(s2.ptr[0]);
        else if (s2.size == 0)
            return s1.ptr[0];
        else
        {
            int n = (s1.size > s2.size) ? s1.size : s2.size;
            for (int i = 0; i < n; i++)
            {
                if (s1.ptr[i] != s2.ptr[i])
                {
                    return s1.ptr[i] - s2.ptr[i];
                }
            }

            if (s1.size > s2.size)
                return s1.ptr[n];
            else if (s1.size < s2.size)
                return -(s2.ptr[n]);
            else
                return 0;
        }
    }

    friend String operator+(String &, String &);
    friend int operator>(String &, String &);
    friend int operator>=(String &, String &);
    friend int operator<(String &, String &);
    friend int operator<=(String &, String &);
};

String operator+(String &s1, String &s2)
{
    String s;
    s.size = s1.size + s2.size;
    s.ptr = new char[s.size];
    for (int i = 0; i < s1.size; i++)
        s.ptr[i] = s1.ptr[i];
    for (int j = 0; j < s2.size; j++)
        s.ptr[s1.size + j] = s2.ptr[j];
    return s;
}

int operator>(String &s1, String &s2)
{
    int k = String::scmp(s1, s2);
    if (k > 0)
        return 1;
    else
        return 0;
}

int operator>=(String &s1, String &s2)
{
    int k = String::scmp(s1, s2);
    if (k >= 0)
        return 1;
    else
        return 0;
}

int operator<(String &s1, String &s2)
{
    int k = String::scmp(s1, s2);
    if (k < 0)
        return 1;
    else
        return 0;
}

int operator<=(String &s1, String &s2)
{
    int k = String::scmp(s1, s2);
    if (k <= 0)
        return 1;
    else
        return 0;
}
} // namespace StringNamespace