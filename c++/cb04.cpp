#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl<<a-b<<endl<<a*b<<endl;
    if(b==0) cout<<"INF";
    else printf("%.2f",(float)a/b);
}