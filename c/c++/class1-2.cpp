#include "class1.cpp"
class Student:public Person{
    private:
    double gpa;
    public:
    Student(string name,int age,string bd, double gpa):Person(name,age,bd){
        this->gpa=gpa;
    }
    double getgpa(){
        return gpa;
    }
    void setgpa(double d){
        gpa=d;
    }
    void display(){
        Person::display();
        cout<<"GPA: "<<gpa<<endl;
    }
};