#include<iostream>
#include<string>
using namespace std;

// base class Person
class Person{
    public:
    string name;
    int age;
    
    Person(){
        name="";
        age=0;
    }
    
    Person(string n,int a){
        name=n;
        age=a;
    }
    
    // virtual function for displaying info
    virtual void displayInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    
    // virtual function for polymorphism
    virtual void showRole(){
        cout<<"Role: Person"<<endl;
    }
};

// Student class inherits from Person
class Student:public Person{
    public:
    int rollNumber;
    string course;
    float marks;
    
    Student(){
        rollNumber=0;
        course="";
        marks=0.0;
    }
    
    Student(string n,int a,int roll,string c,float m):Person(n,a){
        rollNumber=roll;
        course=c;
        marks=m;
    }
    
    // override displayInfo function
    void displayInfo(){
        Person::displayInfo();
        cout<<"Roll Number: "<<rollNumber<<endl;
        cout<<"Course: "<<course<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
    
    void showRole(){
        cout<<"Role: Student"<<endl;
    }
    
    // function to check student grade
    void checkGrade(){
        if(marks>=90) cout<<"Grade: A+"<<endl;
        else if(marks>=80) cout<<"Grade: A"<<endl;
        else if(marks>=70) cout<<"Grade: B"<<endl;
        else if(marks>=60) cout<<"Grade: C"<<endl;
        else cout<<"Grade: F"<<endl;
    }
};

// Teacher class also inherits from Person
class Teacher:public Person{
    public:
    string subject;
    int experience;
    
    Teacher(){
        subject="";
        experience=0;
    }
    
    Teacher(string n,int a,string sub,int exp):Person(n,a){
        subject=sub;
        experience=exp;
    }
    
    void displayInfo(){
        Person::displayInfo();
        cout<<"Subject: "<<subject<<endl;
        cout<<"Experience: "<<experience<<" years"<<endl;
    }
    
    void showRole(){
        cout<<"Role: Teacher"<<endl;
    }
};

// main management system class
class StudentManagementSystem{
    private:
    Student students[50];  // array to store students
    Teacher teachers[20];  // array to store teachers
    int studentCount;
    int teacherCount;
    
    public:
    // constructor to initialize counts
    StudentManagementSystem(){
        studentCount=0;
        teacherCount=0;
    }
    
    // function to add new student
    void addStudent(){
        if(studentCount>=50){
            cout<<"Cannot add more students!"<<endl;
            return;
        }
        
        string name,course;
        int age,roll;
        float marks;
        
        // taking input from user
        cout<<"\n--- Add New Student ---"<<endl;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter roll number: ";
        cin>>roll;
        cout<<"Enter course: ";
        cin>>course;
        cout<<"Enter marks: ";
        cin>>marks;
        
        // creating student object and adding to array
        students[studentCount]=Student(name,age,roll,course,marks);
        studentCount++;
        cout<<"Student added successfully!"<<endl;
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    // function to add new teacher
    void addTeacher(){
        if(teacherCount>=20){
            cout<<"Cannot add more teachers!"<<endl;
            return;
        }
        
        string name,subject;
        int age,experience;
        
        cout<<"\n--- Add New Teacher ---"<<endl;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter subject: ";
        cin>>subject;
        cout<<"Enter experience: ";
        cin>>experience;
        
        teachers[teacherCount]=Teacher(name,age,subject,experience);
        teacherCount++;
        cout<<"Teacher added successfully!"<<endl;
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    // function to display all students
    void displayAllStudents(){
        cout<<"\n--- All Students ---"<<endl;
        if(studentCount==0){
            cout<<"No students found!"<<endl;
            return;
        }
        
        // loop through all students
        for(int i=0;i<studentCount;i++){
            cout<<"\nStudent "<<(i+1)<<":"<<endl;
            students[i].displayInfo();
            students[i].showRole();
            students[i].checkGrade();
            cout<<"------------------------"<<endl;
        }
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    void displayAllTeachers(){
        cout<<"\n--- All Teachers ---"<<endl;
        if(teacherCount==0){
            cout<<"No teachers found!"<<endl;
            return;
        }
        
        for(int i=0;i<teacherCount;i++){
            cout<<"\nTeacher "<<(i+1)<<":"<<endl;
            teachers[i].displayInfo();
            teachers[i].showRole();
            cout<<"------------------------"<<endl;
        }
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    // function to search student by roll number
    void searchStudent(){
        if(studentCount==0){
            cout<<"No students found!"<<endl;
            return;
        }
        
        int roll;
        cout<<"Enter roll number: ";
        cin>>roll;
        
        // searching for student
        for(int i=0;i<studentCount;i++){
            if(students[i].rollNumber==roll){
                cout<<"\nStudent Found:"<<endl;
                students[i].displayInfo();
                students[i].checkGrade();
                cout<<"\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                return;
            }
        }
        
        cout<<"Student not found!"<<endl;
    }
    
    // function to demonstrate polymorphism
    void showPolymorphism(){
        cout<<"\n--- Polymorphism Demo ---"<<endl;
        
        if(studentCount>0){
            cout<<"First Student:"<<endl;
            Person* p1=&students[0];  // polymorphism example
            p1->showRole();  // virtual function call
            p1->displayInfo();
            cout<<"------------------------"<<endl;
        }
        
        if(teacherCount>0){
            cout<<"First Teacher:"<<endl;
            Person* p2=&teachers[0];
            p2->showRole();
            p2->displayInfo();
            cout<<"------------------------"<<endl;
        }
        
        if(studentCount==0 && teacherCount==0){
            cout<<"Add students and teachers first!"<<endl;
        }
        
        cout<<"\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
};

// main function
int main(){
    StudentManagementSystem sms;
    int choice;
    
    cout<<"=== Student Management System ==="<<endl;
    
    // main program loop
    while(true){
        cout<<"\n--- Menu ---"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Add Teacher"<<endl;
        cout<<"3. Show All Students"<<endl;
        cout<<"4. Show All Teachers"<<endl;
        cout<<"5. Search Student"<<endl;
        cout<<"6. Polymorphism Demo"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        
        if(choice==1){
            sms.addStudent();
        }
        else if(choice==2){
            sms.addTeacher();
        }
        else if(choice==3){
            sms.displayAllStudents();
        }
        else if(choice==4){
            sms.displayAllTeachers();
        }
        else if(choice==5){
            sms.searchStudent();
        }
        else if(choice==6){
            sms.showPolymorphism();
        }
        else if(choice==7){
            cout<<"Goodbye!"<<endl;
            break;
        }
        else{
            cout<<"Wrong choice!"<<endl;
        }
    }
    
    return 0;
}
