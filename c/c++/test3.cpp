#include <iostream>
#include <math.h>
using namespace std;
class Point{
    private:
    double x;
    double y;
    public:
    Point(){

    }
    Point(double x,double y){
        this->x=x;
        this->y=y;
    }
    void setX(double x){
        this->x=x;
    }
    void setY(double y){
        this->y=y;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void setXY(double x,double y){
        this->x=x;
        this->y=y;
    }
    double distance(double a,double b){
        double d=sqrt(pow(x-a,2)+pow(y-b,2));
        return d;
    }
    double distance(Point p){
        return distance(p.getX(),p.getY());
    }
};
int main() {
	Point p1(1.5, 6.7);
	Point p2(2.8, 3.2);
	cout << p1.distance(p2) << endl;
	cout << p1.distance(2.34, 7.8) << endl;
	return 0;
}