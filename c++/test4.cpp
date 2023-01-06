#include <iostream>
using namespace std;
class Account{
    private:
    int id;
    string name;
    int balance;
    public:
    Account(int a,string b){
        this->id=a;
        this->name=b;
    }
    Account(int a,string b,int c){
        this->id=a;
        this->name=b;
        this->balance=c;
    }
    void setName(string name){
        this->name=name;
    }
    int getId(){
        return id;
    }
    int getBalance(){
        return balance;
    }
    string getName(){
        return name;
    }
    void deposit(int a){
        this->balance+=a;
    }
    void withraw(int a){
        if(balance>=a){
            this->balance-=a;
        }
        else {
            cout<<"That amount exceeds your current balance.​"<<endl;
        }
    }
    void display(){
        cout<<"Id: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};