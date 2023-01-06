#include<iostream>
#include<string>
#include <iomanip>

using namespace std;
class RetailItem
{
    private:
    string description;
    int unitsOnHand;
    float price;
    public:
    RetailItem(string description, int unitsOnHand, float price)
    {
        this -> description = description;
        this -> unitsOnHand = unitsOnHand;
        this -> price = price;

    }
    void setDescription()
    {
        this -> description = description;
    }
    string getDescription()
    {
        return description;
    }
    void setunitsOnHand()
    {
        this -> unitsOnHand = unitsOnHand;
    }
    int getunitsOnHand()
    {
        return unitsOnHand;
    }
    void setPrice()
    {
        this -> price = price;
    }
    float getPrice()
    {
        return price;
    }
    void display()
    {
        cout  <<setw(15)<<left<< getDescription() << setw(16)<<left<< getunitsOnHand() <<setw(9)<<left<< getPrice() << endl;
    }
};


int main()
{

    cout<<setw(15)<<left<<"Description"<<setw(16)<<left<<"Unit On Hand"<<setw(9)<<left<<"Price" << endl;
    RetailItem a("Designer", 40, 34.95);
    RetailItem b("Jacket", 12, 59.95);
    RetailItem c("Shirt", 20, 24.95);
    a.display();
    b.display();
    c.display();
    return 0;
}