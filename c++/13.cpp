#include<iostream>
#include "modular_exponentiation_and_modular_binomial_coefficient.cpp"

using namespace std;

int main(){
	long long num,m=0;
	int k;
	cin>>num>>k;
	for(int i=1;i<=num;i++){
		cout<<bc(num,i)<<endl;
	}
}
