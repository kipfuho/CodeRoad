#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if((a==0&&b==0&&c!=0)||(d==0&&e==0&&f!=0)){
        cout<<"VONGHIEM";
        return 0;
    }
    if(a*e==b*d && a*f==d*c){
        if(b*f==e*c) cout<<"VOSONGHIEM";
        else cout<<"VONGHIEM";
        return 0;
    }
    double x,y;
    if(a==0){
        y=c/b;
        x=(f-e*y)/d;
    }
    else if(b==0){
        x=c/a;
        if(e==0){
            if(d*x==f){
                cout<<"VOSONGHIEM";
                return 0;
            }
            else{
                cout<<"VONGHIEM";
                return 0;
            }
        }
        else{
            y=(f-d*x)/e;
        }
    }
    else{
        if((e-(b*d)/a)==0){
            if((d*c)/a==f){
                cout<<"VOSONGHIEM";
                return 0;
            }
            else{
                cout<<"VONGHIEM";
                return 0;
            }
        }
        else{
            y=((f-(d*c)/a)/(e-(b*d)/a));
            x=(c-b*y)/a;
        }
    }
    if(x==0) printf("0.00 %.2lf",y);
    else if(y==0) printf("%.2lf 0.00",x);
    else printf("%.2lf %.2lf",x,y);
}