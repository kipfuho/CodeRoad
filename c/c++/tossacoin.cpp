#include<iostream>
#include <ctime>

using namespace std;

class Coin{
    private:
    string sideUp;
    int h;
    int t;
    public:
    Coin(){
        int a=rand() % (1-0+1)+0;
        if(a==1)sideUp="heads";
        else sideUp="tails";
    }
    void toss(){
        int a=rand() % (1-0+1)+0;
        if(a==1){
            sideUp="heads";
            h+=1;
        }
        else{ 
            sideUp="tails";
            t+=1;
        }
    }
    void display(){
        cout<<sideUp<<endl;
    }
    int heads(){
        return h;
    }
    int tails(){
        return t;
    }
};

int main(){
    srand(time(NULL));
    Coin c;
    cout<<"Mat luc dau la :";
    c.display();
    for(int i=0;i<20;i++){
        cout<<i+1<<": ";
        c.toss();
        c.display();
    }
    cout<<"sau 20 lan tung"<<endl;
    cout<<"so lan ngua la: "<<c.heads()<<endl;
    cout<<"so lan sap la: "<<c.tails();
}