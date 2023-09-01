#pragma once
#include<iostream>
using namespace std;
class Person{
    private:
    string name;
    int age;
    string bd;
    public:
    Person(string name,int age,string bd){
        this->name=name;
        this->age=age;
        this->bd=bd;
    }
    string getname(){
        return name;
    }
    int getage(){
        return age;
    }
    string getbd(){
        return bd;
    }
    void setname(string name){
        this->name=name;
    }
    void setage(int age){
        this->age=age;
    }
    void setbd(string bd){
        this->bd=bd;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Birth Day: "<<bd<<endl;
    }
};