#include<bits/stdc++.h>
using namespace std;

class ToaDo{
    private:
    double x;
    double y;
    public:
    ToaDo(){
        x=0;
        y=0;
    }
    ToaDo(double x,double y){
        this->x=x;
        this->y=y;
    }
    double getx(){
        return x;
    }
    double gety(){
        return y;
    }
    void setx(double x){
        this->x=x;
    }
    void sety(double y){
        this->y=y;
    }
} A[3];

int main(){
    for(int i=0;i<2;i++){
        double x,y;
        printf("Nhap hoanh do diem %c : ",'A'+i);
        cin>>x;
        printf("Nhap tung do diem %c : ",'A'+i);
        cin>>y;
        A[i].setx(x); A[i].sety(y);
    }
    double  d=sqrt(pow(A[0].getx()-A[1].getx(),2)+pow(A[0].gety()-A[1].gety(),2));
    cout<<"Khoang cach A va B la: "<<d;
}
