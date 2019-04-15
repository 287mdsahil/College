#include<iostream>
#include<fstream>
#include<utility>
#include<string.h>
#include<time.h>
using namespace std;
#define Max 100



class student{
    int roll;
    char name[31];
    char course[21];
    char admission_date[31];
    pair<char[31],int> marks[5];

    int genRoll(int courseId){
        char course[31];
        int r=0;
        switch (courseId)
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
        int maxr=-1;
        ifstream f;
        student s;
        f.open("student.txt", ios::in | ios::binary);
        while(f.read((char*)&s, sizeof(s))){
            if(s.getRoll()>maxr && strcmp(s.getCourse(),course)==0)
                maxr=(s.getRoll())%100;
        }
        f.close();
        if(maxr==-1) maxr=0;
        roll = courseId*100+(maxr+1);
    }

    public:

    student(int t=-1){
        roll=t;
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
                genRoll(1);
                break;
            case 2:
                strcpy(course,"Etce");
                genRoll(2);
                break;
            
            case 3:
                strcpy(course,"Electrical");
                genRoll(3);
                break;

            default:
                break;
        }
        for(int i=0;i<5;i++){
            cout<<"Enter marks in "<<marks[i].first<<": "; 
            cin>>marks[i].second;
        }
        cin.ignore(100,'\n');
        
   		time_t now = time(0);
   		char dt[100];
        strcpy(admission_date,ctime(&now));
        return;
    }

    void updateData(){
        cout<<"1. Update name"<<endl;
        cout<<"2. Update Course"<<endl;
        cout<<"3. Update admission date"<<endl;
        cout<<"4. Update marks in "<<marks[0].first<<endl;
        cout<<"5. Update marks in "<<marks[1].first<<endl;
        cout<<"6. Update marks in "<<marks[2].first<<endl;
        cout<<"7. Update marks in "<<marks[3].first<<endl;
        cout<<"8. Update marks in "<<marks[4].first<<endl;
        cout<<"Enter choice: ";
        int choice;
        cin>>choice;
        cin.ignore(100,'\n');
        switch(choice){
            case 1:{
                cout<<"Enter new name: ";
                char n_name[31];
                cin.getline(n_name,31);
                strcpy(name,n_name);
                break;
            }

            case 2:{
                cout<<"Course options: "<<endl;
                cout<<"1.Cse\n2.Etce\n3.Electrical\nEnter new choice: ";
                int courseChoice;
                cin>>courseChoice;
                cin.ignore(100,'\n');
                switch (courseChoice)
                {
                    case 1:
                        strcpy(course,"Cse");
                        genRoll(1);
                        break;
                    case 2:
                        strcpy(course,"Etce");
                        genRoll(2);
                        break;
            
                    case 3:
                        strcpy(course,"Electrical");
                        genRoll(3);
                        break;

                    default:
                        cout<<"Invalid input!"<<endl;
                        break;
                }
                break;
            }

            case 3:{
                cout<<"Enter new admission date: ";
                char n_admission_date[11];
                cin.getline(n_admission_date,11);
                strcpy(admission_date,n_admission_date);
                break;
            }   

            case 4:
                cout<<"Enter new marks in "<<marks[0].first<<": ";
                cin>>marks[0].second;
                break;
            
            case 5:
                cout<<"Enter new marks in "<<marks[1].first<<": ";
                cin>>marks[1].second;
                break;

            case 6:
                cout<<"Enter new marks in "<<marks[2].first<<": ";
                cin>>marks[2].second;
                break;

            case 7:
                cout<<"Enter new marks in "<<marks[3].first<<": ";
                cin>>marks[3].second;
                break;

            case 8:
                cout<<"Enter new marks in "<<marks[4].first<<": ";
                cin>>marks[4].second;
                break;

            default :
                cout<<"Invalid choice!"<<endl;
                break;
        }
    }

    void showData(){
        cout<<"Roll no.: "<<roll<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Admission date: "<<admission_date;
        for(int i=0;i<5;i++)
            cout<<"Marks in "<<marks[i].first<<": "<<marks[i].second<<endl;
        cout<<"Grade: "<<getGrade()<<endl;
        return;
    }

    void displayMarksheet(){
        cout<<endl<<endl;;
        cout<<"\tName\t\t\t: "<<getName()<<endl;
        cout<<"\tRoll\t\t\t: "<<getRoll()<<endl;
        cout<<"\tCourse\t\t\t: "<<getCourse()<<endl;
        cout<<"\tAdmission date\t\t: "<<getAdmissionDate()<<endl;  
        cout<<"\t_________________________________________"<<endl;
        cout<<"\t|\t\tMARKSHEET\t\t|"<<endl;
        cout<<"\t-----------------------------------------"<<endl;
        cout<<"\t| "<<marks[0].first<<"\t\t\t: "<<marks[0].second<<"\t|"<<endl;
        cout<<"\t| "<<marks[1].first<<"\t\t\t\t: "<<marks[1].second<<"\t|"<<endl;
        cout<<"\t| "<<marks[2].first<<"\t\t\t: "<<marks[2].second<<"\t|"<<endl;
        cout<<"\t| "<<marks[3].first<<"\t\t\t: "<<marks[3].second<<"\t|"<<endl;
        cout<<"\t| "<<marks[4].first<<"\t\t\t\t: "<<marks[4].second<<"\t|"<<endl;
        cout<<"\t-----------------------------------------"<<endl;
        cout<<"\t| CGPA\t\t\t\t: "<<getGrade()<<"\t|"<<endl;
        cout<<"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<endl;
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

    char* getAdmissionDate(){
        return admission_date;
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
                if(strcmp(s[i].getCourse(),s[j].getCourse())>1){
                    student dummy=s[i];
                    s[i]=s[j];
                    s[j]=dummy;
                }
                else if(s[i].getCourse()==s[j].getCourse() && s[i].getRoll()>s[i].getRoll()){
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
                else if(s[i].getGrade()==s[j].getGrade() && s[i].getRoll()>s[i].getRoll()){
                    student dummy=s[i];
                    s[i]=s[j];
                    s[j]=dummy;
                }
            }
        }
    }

    public:

    student retStudent(int k){
        ifstream f;
        student s;
        f.open(file, ios::in | ios::binary);
        f.seekg((k)*sizeof(student),ios::beg);
        f.read((char*)&s,sizeof(s));
        f.close();
        return s;
    }
    
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

    student removeStudent(int r){
        fstream f("student.txt", ios::binary | ios::in | ios::out);
        student s;
        while(f.read((char*)&s,sizeof(s))){
            if(s.getRoll()==r){
                f.seekp(-1*sizeof(s),ios::cur);
                student dummy;
                f.write((char*)&dummy,sizeof(dummy));
                return s;
            }
        }
        f.close();
        cout<<"Corresponding entry does not exist!"<<endl;
        getchar();
        student dummy;
        return dummy;
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
    
    void updateInfo(int r){
        int k = searchRoll(r);
        if(k==-1){
            cout<<"Entry doesn't exist!"<<endl;
            getchar();
            return;
        }
        student s = retStudent(k);
        cout<<endl;
        cout<<"Current record:----------"<<endl;
        s.showData();
        cout<<endl;
        s.updateData();
        cout<<endl;
        cout<<"Updated record:----------"<<endl;
        s.showData();
        cout<<endl;
        cout<<"Confirm Update?(y/n): ";
        char choice;
        cin>>choice;
        cin.ignore(100,'\n');
        if(choice=='y'){
            removeStudent(r);
            addStudent(s);
        }
        else{
            cout<<"Update aborted!"<<endl;
            
        }
    }

    void defrag(){
        char file_new[31];
        strcpy(file_new,"student_new.txt");
        ifstream f_old(file, ios::in | ios::binary);
        ofstream f_new(file_new, ios::out | ios::binary);
        student s;
        while(f_old.read((char*)&s,sizeof(s))){
            if(s.getRoll()!=-1)
                f_new.write((char*)&s,sizeof(s));
        }

        f_new.close();
        f_old.close();
        remove(file);
        rename(file_new,file);
        getchar();
        return;
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
            cout<<"7.Defrag file"<<endl;
            cout<<"8.Exit"<<endl;

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
                    student s = sfile.removeStudent(r);
                    cout<<endl<<"Entry deleted:"<<endl;
                    s.showData();
                    getchar();
                    break;
                }

                case 5:{
                    cout<<"Enter the roll no of the student: ";
                    int r;
                    cin>>r;
                    cin.ignore(100,'\n');
                    sfile.updateInfo(r);
                    break;
                }

                case 6:{
                    cout<<"Enter the roll no of the student: ";
                    int r;
                    cin>>r;
                    cin.ignore(100,'\n');
                    int k = sfile.searchRoll(r);
                    student s = sfile.retStudent(k);
                    s.displayMarksheet();
                    getchar();
                    break;
                }

                case 7:
                    sfile.defrag();
                    break;

                case 8:
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