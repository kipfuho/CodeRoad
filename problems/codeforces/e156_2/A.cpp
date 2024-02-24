// https://codeforces.com/contest/1886/problem/A
// why runtime error? -> because return 1; in main()

#include<iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n < 10){
            if(n == 7){
                cout << "YES" << endl << "1 2 4" << endl;
            }
            else if(n == 8){
                cout << "YES" << endl << "1 2 5" << endl;
            }
            else cout << "NO" << endl;
        }
        else{
            int floor = (int) n/3, mod = n%3;
            if(mod == 0){
                int x = 1, y = 4, z = (floor - 1)*3 - 2;
                cout << "YES" << endl;
                cout << x << " " << y << " " << z << endl;
            }
            else{
                int x = mod, y = 4, z = (floor - 1)*3 - 1;
                cout << "YES" << endl;
                cout << x << " " << y << " " << z << endl;
            }
        }
    }
    return 1;
}