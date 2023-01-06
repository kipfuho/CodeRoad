#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<r;i++)
using namespace std;

int n;

string a[8]={"","","1","7","4","2","6","8"};

string filler(int k, char ch){
    string s="";
    while(k){
        s+=ch;
        k--;
    }
    return s;
}

string min_t(int x){
    if(x<=7) return a[x];
    else{
        int div=x/7;
        int mod=x%7;
        switch (mod){
            case 0: return (filler(div,'8')); break;
            case 1: return ("10"+filler(div-1,'8')); break;
            case 2: return ("1"+filler(div,'8')); break;
            case 3: {
                if(x>=17) return ("200"+filler((x-17)/7,'8'));
                return ("22");
            } break;
            case 4: return ("20" + filler((x - 11) / 7, '8')); break;
            case 5: return ("2" + filler(div, '8')); break;
            case 6: return ("6" + filler(div, '8')); break;
        }
    }
    return "";
}

string max_t(int x){
    if (x % 2 == 1) return ("7" + filler(x / 2 -1, '1'));
	else return filler(x / 2, '1');
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<min_t(n)<<" "<<max_t(n)<<endl;
    }
}