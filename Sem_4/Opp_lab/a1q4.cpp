#include<iostream>
using namespace std;

class student{
    int roll;
    char name[31];
    char course[31];
    char admission_date[11];
    int marks[5];

    public:

    void setData(){
        cout<<"Enter roll no.: ";
        cin>>roll;
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter the course: ";
        cin>>course;
        cout<<"Enter the admission date: ";
        cin>>admission_date;
        cout<<"Enter the marks of the 5 subjects: ";
        for(int i=0;i<5;i++) 
            cin>>marks[i];
        return;
    }

    void showData(){
        cout<<"Roll no.: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Admission date: "<<admission_date<<endl;
        cout<<"Marks:";
        for(int i=0;i<5;i++)
            cout<<" "<<marks[i];
        cout<<endl;
        return;
    }
};

int main(){

    student s;
    s.setData();
    s.showData();
    return 0;
}