#include<iostream>

using namespace std;

int main(){
	int x, y=3, z=20;
	x = ++y + 2*(y+z) + z++;
	printf("%d %d %d", x, y, z);
}
