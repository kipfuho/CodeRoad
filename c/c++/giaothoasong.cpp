#include<bits/stdc++.h>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)
using namespace std;

const int nmax=100001;
int bit[nmax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double s,d1,d2; cin>>s;
    int kmax=(int) s;
    int nmin=(int)min(s/2,(s-1)/2)+1;
    FOR(k,0,kmax){
        int n=nmin;
        while(n<=10){
            if(k&1){
                d1=(2*n+1+k)/2,d2=(2*n+1-k)/2;
            }
            else{
                d1=(2*n+k)/2,d2=(2*n-k)/2;
            }
            double cosa=(d2*d2+s*s-d1*d1)/(2*s*d2);
            if(cosa<0){
                double cosb=sqrt(1-cosa*cosa);
                double h=cosb*d2;
                printf("k=%-4d n=%-4d h=%-8.3lf\n",k,n,h);
            }
            else{
                double sina=sqrt(1-cosa*cosa);
                double h=sina*d2;
                printf("k=%-4d n=%-4d h=%-8.3lf\n",k,n,h);
            }
            n++;
        }
    }
}