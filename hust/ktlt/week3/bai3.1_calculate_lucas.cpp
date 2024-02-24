// Nguyen Dinh Ut Biu 20215317
// Bai3.1: Viet ham tinh so Lucas thu n

#include<iostream>

using namespace std;

// Ham tinh so Lucas thu n
int lucas(int n) {
    if(n < 2) return 2 - n;
    return lucas(n - 1) + lucas(n - 2);
}

int main(){
	int n; cin >> n;
	cout << lucas(n);
}
