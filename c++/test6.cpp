#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void openFile(string read,string write){
    ifstream a;
    fstream b;
    a.open(read);
    b.open(write);
    if(a.is_open()&&b.is_open()) {cout<<"Good"<<endl;}
    else{cout<<"Failed"<<endl;}
    a.close();
    b.close();
}

int countEven(string read){
    int t,m=0;
    ifstream a;
    a.open(read);
    while(a>>t){
        if(t%2==0) m++;
    }
    return m;
}
int main () {
    string a,b;
        cout<<"nhap ten file doc va file ghi"<<endl;
        cin>>a>>b;
        openFile(a,b);
    cout<<countEven(a);
}