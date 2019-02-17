#include<iostream>
#include<fstream>
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

    int getRoll(){
        return roll;
    }

    char* getName(){
        return name;
    }

    char* getCourse(){ 
        return course;
    }

    pair<char[31],int>* getMarks(){
        return marks;
    }
};

class student_file{
    char file[51];
    
    public:

    int searchRoll(int r){
        ifstream f;
        student s;
        int k=0;
        f.open(file, ios::in | ios::binary);
        while(f.read((char*)&s, sizeof(s))){
            if(s.getRoll()==r)
                return k;
            k++;
        }
        f.close();
        return -1;
    }

    void open(char* s){
        strcpy(file,s);
    }

    student_file(){
    }

    student_file(char *f){
        strcpy(file,f);
    }

    void addStudent(student s){
        if(searchRoll(s.getRoll())!=-1){
            cout<<"Roll no already exists!!"<<endl;
            getchar(); 
            return;
        }
        ofstream f;
        f.open(file, ios::out | ios::binary);
        f.write((char*)&s,sizeof(s));
        f.close();
        return;
    }

    void displayAll(){
        ifstream f("student.txt", ios::binary | ios::in);
        student s;
        while(f.read((char*)&s,sizeof(s))){
            cout<<endl;
            s.showData();
        }
        f.close();
    }
};


class userInterface{
    student_file sfile;
    public:

    userInterface(char* s){
        sfile.open(s);
    }

    void showMenu(){
        while(1){
            system("clear");
            cout<<"------------MENU------------:"<<endl;
            cout<<"1.Display all students"<<endl;
            cout<<"2.Display no of admitted students"<<endl;
            cout<<"3.New student admission"<<endl;
            cout<<"4.Expell student"<<endl;
            cout<<"5.Update student Info"<<endl;
            cout<<"6.Display student marksheet"<<endl;
            cout<<"7.Exit"<<endl;

            int choice;
            cout<<"Enter choice: ";
            cin>>choice;
            cin.ignore(100,'\n');

            switch(choice){

                case 1:
                    userInterface::sfile.displayAll();
                    getchar();
                    break;

                case 7:
                    return;

                default:
                    cout<<"Invalid Input!"<<endl;
                    getchar();
                    break;
            }
        }
    }
};

int main(){
    char s[51];
    strcpy(s,"student.txt");
    userInterface interface(s);
    interface.showMenu();
    return 0;
}