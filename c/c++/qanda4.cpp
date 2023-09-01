#include<bits/stdc++.h>
using namespace std;

class Time{
    private:
    int gio;
    int phut;
    int giay;
    public:
    Time(){
        gio=0;
        phut=0;
        giay=0;
    }
    Time(int a,int b,int c){
        gio=a;
        phut=b;
        giay=c;
    }
    int get_gio(){
        return gio;
    }
    int get_phut(){
        return phut;
    }
    int get_giay(){
        return giay;
    }
    void set_gio(int a){
        gio=a;
    }
    void set_phut(int b){
        phut=b;
    }
    void set_giay(int c){
        giay=c;
    }
    void hien_thi_1(){
        cout<<gio<<":"<<phut<<":"<<giay<<endl;
    }
    void hien_thi_2(){
        if(gio>=12){
            cout<<gio-12<<":"<<phut<<":"<<giay<<" PM"<<endl;
        }
        else{
            cout<<gio<<":"<<phut<<":"<<giay<<" AM"<<endl;
        }
    }
};

int main(){
    Time A(12,0,0);
    A.set_phut(30);
    A.hien_thi_1();
    A.hien_thi_2();
}
