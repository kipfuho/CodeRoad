#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a==0&&b!=0) cout<<"NO";
    else if(a==0&&b==0) cout<<"INF";
    else printf("%.2f",(float)-b/a);
}