#include<iostream>
using namespace std;
int main(){
    char a,b;
    scanf("%c %c",&a,&b);
    for(int i=a-32;i<=b-32;i++)printf("%c ",i);
}