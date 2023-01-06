#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    long long* arr;
    arr=new long long[T];
    for (int i=0;i<T;i++){
        cin>>arr[3*i]>>arr[3*i+1]>>arr[3*i+2];
    }
    for (int i=0;i<T;i++){
        int a=0;
        for (int j=3*i;j<3*(i+1);j++){
            if (arr[j]==2021){
                cout<<"YES"<<endl;
                a++;
                break;
            }
        
        }
        if (a==0){
            cout<<"NO"<<endl;
        }
    }
    delete[] arr;
    return 0;
}