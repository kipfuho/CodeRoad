// Nguyen Dinh Ut Biu 20215317
// Bài 4.2: Tinh dien tich tam giac

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
	// calculate length of 3 edges
    double la = sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
    double lb = sqrt((b.first - c.first)*(b.first - c.first) + (b.second - c.second)*(b.second - c.second));
    double lc = sqrt((c.first - a.first)*(c.first - a.first) + (c.second - a.second)*(c.second - a.second));
    // calculate half perimeter
	double p = (la + lb + lc) / 2.0; 
	// calculate area using Heron formula
    return sqrt(p*(p-la)*(p-lb)*(p-lc));
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
   return 0;
}
