/*
Description
Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
Input
Line 1 contains 3 positive integers a, b, c 
Output
Write NO SOLUTION if the given equation has no solution 
Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 

Example
Input 
1 1 8
Output 
NO SOLUTION 


Input 
1 -2 1
Output
1.00

Input 
1 -7 10
Output 
2.00 5.00
*/

#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int a, b, c; cin >> a >> b >> c;
    double delta = b*b - 4*a*c;
    if(delta < 0){
        cout << "NO SOLUTION";
        return 0;
    }
    if(delta == 0){
        printf("%.2lf", (double)-b/2.0/a);
    }
    else{
        double n1 = (double)(-b - sqrt(delta))/2.0/a, n2 = (double)(-b + sqrt(delta))/2.0/a;
        if(n1 > n2) swap(n1, n2);
        printf("%.2lf %.2lf", n1, n2);
    }
}