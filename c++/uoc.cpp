//tong uoc chung cua A va B || tong uoc cua A nhung khong la uoc cua B
#include<bits/stdc++.h>
#define ll long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A,B; cin>>A>>B;
	ll pre1=1,pre2=1,sum1=1,sum2=1,count1=1,count2=1;
	while(A%2==0){
		if(B%2==0){
			pre2+=pow(2,count2++);
			B/=2;
		}
		pre1+=pow(2,count1++);
		A/=2;
	}
	sum1*=pre1; sum2*=pre2;
	for(int i=3;i<=sqrt(A);i+=2){
		pre1=1,pre2=1,count1=1,count2=1;
		if(A%i==0){
			while(A%i==0){
				if(B%i==0){
					pre2+=pow(i,count2++);
					B/=i;
				}
				pre1+=pow(i,count1++);
				A/=i;
			}
		}
		sum1*=pre1; sum2*=pre2;
	}
	if(A>1){
		if(B%A==0) sum2*=(1+A);
		sum1*=(1+A);
	}
	cout<<sum2;
}