#include<iostream>
#include<string>

using namespace std;
class Circle{
    private:
    float radius;
    float pi=3.14159;
    public:
    Circle(){
        radius=0;
    }
    Circle(float radius){
        this->radius=radius;
    }
    float getRadius(){
        return radius;
    }
    void setRadius(float radius){
        this->radius=radius;
    }
    float getArea(){
        return pi*radius*radius;
    }
    float getDiameter(){
        return 2*radius;
    }
    float getCircumference(){
        return 2*pi*radius;
    }
    void display(){
        cout<<"Dien tich = "<<getArea()<<endl;
        cout<<"Duong kinh = "<<getDiameter()<<endl;
        cout<<"Chu vi = "<<getCircumference()<<endl;
    }
};

int main(){
    Circle a(3.3);
    a.display();
}