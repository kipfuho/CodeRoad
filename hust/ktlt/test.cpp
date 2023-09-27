#include <iostream>
#include <vector>

using namespace std;

int x = 0;
void foo(){
    int x = 5;
}

void foo(int a){
    return;
}

int main() {
    int m[2][3] = {{1,2,3},{4,5,6}};
    int i = 1, j = 2;
    cout << i[m][j];
}
