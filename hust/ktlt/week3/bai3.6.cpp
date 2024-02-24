// Nguyen Dinh Ut Biu 20215317
// Tìm uoc chung lon nhat cua hai so nguyên a, b cho truoc.

#include <iostream>
using namespace std;

// Tinh bang de quy
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Tinh bang cach khu de quy
int gcd2(int a, int b){
	// Vong lap den khi a hoac b = 0, khi do gcd(a,b) bang so con lai lon hon 0
    while(a > 0 && b > 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return a == 0 ? b : a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
