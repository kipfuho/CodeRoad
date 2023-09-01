#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int min=*min_element(a,a+n);
    int max=*max_element(a,a+n);
    int j=0,k=0,ans=n,temp=0;
    for(int i=0;i<n;i++){
        if(a[i]==max) j=i;
        if(a[i]==min) k=i;
        if(j!=0 &&k!=0){
            temp=(abs(j-k)+1);
            ans=ans>temp?temp:ans;
        }
    }
    cout<<ans;
}

