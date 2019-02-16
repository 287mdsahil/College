#include<iostream>
#include<utility>
#include<string.h>
using namespace std;

class student{
    int roll;
    char name[31];
    char course[51];
    char admission_date[11];
    pair<char[31],int> marks[5];

    public:

    student(){
        strncpy(marks[0].first,"Physics",31);
        strncpy(marks[1].first,"Maths",31);
        strncpy(marks[2].first,"Chemestry",31);
        strncpy(marks[3].first,"English",31);
        strncpy(marks[4].first,"P.Ed",31);
    }

    void setData(){
        cout<<"Enter roll no.: ";
        cin>>roll;
        cin.ignore(100,'\n');
        cout<<"Enter the name: ";
        cin.getline(name,31);
        cout<<"Enter the course: ";
        cin.getline(course,51);
        cout<<"Enter the admission date: ";
        cin>>admission_date;
        cin.ignore(100,'\n');
        for(int i=0;i<5;i++){
            cout<<"Enter marks in "<<marks[i].first<<": "; 
            cin>>marks[i].second;
        }
        cin.ignore(100,'\n');
        return;
    }

    void showData(){
        cout<<"Roll no.: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Admission date: "<<admission_date<<endl;
        for(int i=0;i<5;i++)
            cout<<"Marks in "<<marks[i].first<<": "<<marks[i].second<<endl;
        return;
    }
};

int main(){

    student s;
    s.setData();
    s.showData();
    //char s[32];
    //cin.getline(s,32);
    //cout<<s;
    //return 0;
}