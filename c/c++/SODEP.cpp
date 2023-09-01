//phien ban loi~

#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;

ll l,r;

int M[11]={0,0,1,1,2,10,20,100,200,1000,2000};
int PRE[11]={0,0,1,10,28,118,298,1198,2998,11998,29998};

ll x2str(string s,int n){
    string x=s;
    if(n&1) s.pop_back();
    reverse(s.begin(),s.end());
    x+=s;
    return stoll(x);
}

ll count(string s){
    int len=s.size(),pre=0;
    int mid=(len+1)/2;
    string x=s.substr(0,mid);
    if(len==1) return 0LL;
    if(len==2){
        if(stoll(s)>=55) return 1;
        else return 0;
    }
    if(len==3){
        if((s[0]+s[1]+s[2]-3*'0')>=10) return s[0]-'0'+1;
        else return 1;
    }
    if(x2str(x,len)>stoll(s)) x=to_string(stoll(x)-1);
    if(mid>x.size()){
        len--;
        mid=x.size();
    }
    int res=PRE[len-1];
    for(int i=0;i<mid;i++){
        if(i==0){
            res+=(x[0]-'1')*M[len];
            pre+=2*(x[0]-'0');
            continue;
        }
        else if(len-2*i==2){
            int temp1=2*(x[mid-1]-'0')+pre;
            int temp2=pre-1;
            res+=(temp1/10-temp2/10);
            break;
        }
        else if(len-2*i==3){
            int temp1=2*(x[mid-2]-'0')+x[mid-1]-'0'+pre;
            int temp2=temp1-(x[mid-1]-'0')-1;
            if((temp1/10-temp2/10)==1) res++;
            res+=(x[mid-2]-'0');
            break;
        }
        else{
            res+=(x[i]-'0')*M[len-2*i];
            pre+=2*(x[i]-'0');
        }
    }
    return res;
}
int main(){
    while(cin>>l>>r){
        l--; 
        cout<<count(to_string(r))-count(to_string(l))<<endl;
    }
}