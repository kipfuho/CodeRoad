#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==0){
        if(b==0&&c!=0) cout<<"NO";
        else if(b==0&&c==0) cout<<"INF";
        else printf("%.2f",(float)-c/b);
    }
    else{
        double d=b*b-4*a*c;
        if(d<0) cout<<"NO";
        else if(d==0) printf("%.2f",(float)-b/(2*a));
        else{
            double x1=(-b+sqrt(d))/(2*a);
            double x2=(-b-sqrt(d))/(2*a);
            if(x1>x2) printf("%.2f %.2f",x2,x1);
            else printf("%.2f %.2f",x1,x2);
        }
    }
}