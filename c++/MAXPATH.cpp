#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main(){
    int m,n,res;
    cin>>m>>n;
    int map[m][n],path[m][n]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin>>map[i][j];
    }
    if(m==1){
        int s=0;
        for(int i=0;i<n;i++) s+=map[0][i];
        cout<<s;
        return 0;
    }
    if(n==1){
        int t=map[0][0];
        for(int i=0;i<m;i++){
            if(map[i][0]>t) t=map[i][0];
        }
        cout<<t;
        return 0;
    }
    for(int i=0;i<m;i++) path[i][0]=map[i][0];
    for(int j=1;j<n;j++){
        for(int i=0;i<m;i++){
            if(i==0) path[0][j]=max(map[0][j]+path[0][j-1],map[0][j]+path[1][j-1]);
            else if(i==m-1) path[m-1][j]=max(map[m-1][j]+path[m-1][j-1],map[m-1][j]+path[m-2][j-1]);
            else path[i][j]=max(max(map[i][j]+path[i][j-1],map[i][j]+path[i-1][j-1]),max(map[i][j]+path[i][j-1],map[i][j]+path[i+1][j-1]));
        }
    }
    res=path[0][n-1];
    for(int i=1;i<m;i++){
        if(path[i][n-1]>res) res=path[i][n-1];
    }
    cout<<res;
}