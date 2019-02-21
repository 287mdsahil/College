#include<iostream>
#include<fstream>
#include<utility>
#include<string.h>
using namespace std;
#define Max 100



class student{
    int roll;
    char name[31];
    char course[21];
    char admission_date[11];
    pair<char[31],int> marks[5];

    public:

    student(){
        roll=-1;
        strncpy(marks[0].first,"Physics",31);
        strncpy(marks[1].first,"Maths",31);
        strncpy(marks[2].first,"Chemestry",31);
        strncpy(marks[3].first,"English",31);
        strncpy(marks[4].first,"P.Ed",31);
    }

    void operator = (const student s){
        roll = s.roll;
        strcpy(name,s.name);
        strcpy(course,s.course);
        strcpy(admission_date,s.admission_date);
        for(int i=0;i<5;i++){
            marks[i].second=s.marks[i].second;
        }

    }

    void setData(){
        cout<<"Enter roll no.: ";
        cin>>roll;
        cin.ignore(100,'\n');
        cout<<"Enter the name: ";
        cin.getline(name,31);
        cout<<"Course options: "<<endl;
        cout<<"1.Cse\n2.Etce\n3.Electrical\nEnter choice: ";
        int courseChoice;
        cin>>courseChoice;
        cin.ignore(100,'\n');
        switch (courseChoice)
        {
            case 1:
                strcpy(course,"Cse");
                break;
            case 2:
                strcpy(course,"Etce");
                break;
            
            case 3:
                strcpy(course,"Electrical");
                break;

            default:
                break;
        }
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
        cout<<"Grade: "<<getGrade()<<endl;
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

    float getGrade(){
        float grade=0;
        for(int i=0;i<5;i++){
            grade+=marks[i].second;
        }
        grade=grade/50;
        return grade;
    }
};



class student_file{
    char file[51];

    void sortDeptWise(student s[Max],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(strcmp(s[i].getName(),s[j].getName())>1){
                    student dummy=s[i];
                    s[i]=s[j];
                    s[j]=dummy;
                }
            }
        }
    }

    void sortGradeWise(student s[Max],int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i].getGrade()>s[j].getGrade()){
                    student dummy=s[i];
                    s[i]=s[j];
                    s[j]=dummy;
                }
            }
        }
    }

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
        f.open(file, ios::out | ios::binary | ios::app);
        f.write((char*)&s,sizeof(s));
        f.close();
        return;
    }

    void removeStudent(int r){
        fstream f("student.txt", ios::binary | ios::in | ios::out);
        student s;
        while(f.read((char*)&s,sizeof(s))){
            if(s.getRoll()==r){
                f.seekp(-1*sizeof(s),ios::cur);
                student dummy;
                f.write((char*)&dummy,sizeof(dummy));
                cout<<endl<<"Entry deleted:"<<endl;
                s.showData();
                getchar();
                return;
            }
        }
        f.close();
        cout<<"Corresponding entry does not exist!"<<endl;
        getchar();
        return;
    }

    void displayAll(){
        ifstream f("student.txt", ios::binary | ios::in);
        student st;
        student s[Max];
        int n =0;
        while(f.read((char*)&st,sizeof(st))){
            if(st.getRoll()>=0){
                s[n]=st;
                n++;
            }
        }
        f.close();

        cout<<"1. Dept wise"<<endl;
        cout<<"2. Grade wise sorted"<<endl;
        cout<<"Enter choice: ";
        int choice;
        cin>>choice;
        cin.ignore(100,'\n');
        switch (choice)
        {
            case 1:
                sortDeptWise(s,n);
                break;

            case 2:
                sortGradeWise(s,n); 
                break;
            default:
                cout<<"Invalid input!"<<endl;
                getchar();
                return;
                break;
        }

        for(int i=0;i<n;i++){
            cout<<endl;
            s[i].showData();
        }
    }
 
    int getCount(){
        ifstream f("student.txt", ios::binary | ios::in);
        student s;
        int count=0;
        while(f.read((char*)&s,sizeof(s))){
            if(s.getRoll()>=0)
                count++;
        }
        return count;
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
                    sfile.displayAll();
                    getchar();
                    break;

                case 2:
                    cout<<"No of students enrolled: "<<sfile.getCount()<<endl;
                    getchar();
                    break;

                case 3:{
                    student student_new;
                    student_new.setData();
                    sfile.addStudent(student_new);
                    break;
                }

                case 4:{
                    cout<<"Enter the roll no of the student: ";
                    int r;
                    cin>>r;
                    cin.ignore(100,'\n');
                    sfile.removeStudent(r);
                    break;
                }

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