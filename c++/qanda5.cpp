#include<bits/stdc++.h>
using namespace std;

class PhanSo{
    private:
    int x;
    int y;
    public:
    PhanSo(){
        x=4;
        y=12;
    }
    double get_tuso(){
        return x;
    }
    double get_mauso(){
        return y;
    }
    void set_tuso(double x){
        this->x=x;
    }
    void set_mauso(double y){
        this->y=y;
    }
    void rutgon(){
        for(int i=2;i<=x;i++){
            if(x%i==0 && y%i==0){
                while(x%i==0 && y%i==0){
                    x/=i;
                    y/=i;
                }
            }
        }
    }
};

int main(){
    PhanSo A;
    A.rutgon();
    cout<<A.get_tuso()<<"/"<<A.get_mauso();
}
