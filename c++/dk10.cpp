#include<iostream>
using namespace std;
int leap_year(int y){
    if(y%100==0) if(y%400==0) return 1; else return 0;
    if(y%4==0) return 1; else return 0;
}

int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int m,y;
    cin>>m>>y;
    if(y<=0||y>100000||m>12) cout<<"INVALID";
    else{
        if(m==2) cout<<d[1]+leap_year(y);
        else cout<<d[m-1];
    }
}