#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double luong[13], soThue[13], phaiNop[13];
    double tongLuong = 0, tongSoThue = 0, tongDaNop = 0, tongCanNop = 0;
    for (int i = 1; i <= 12; i++)
    {
        cout << " nhap luong thang " << i << ": ";
        cin >> luong[i];
        tongLuong = tongLuong+luong[i];
    }
    int nguoiPhuThuoc;
    cout << " Nhap so nguoi phu thuoc cua ban" << endl;
    cin >> nguoiPhuThuoc;
    int bhyt;
    cout << " Ban da dong BHYT chua: " << endl;
    cout << " Nhap 1:r, Nhap 0: c" << endl;
    cin >> bhyt;
    for (int i = 1; i <= 12; i++)
    {
        if (bhyt = 1)
        {
            soThue[i] = luong[i] - nguoiPhuThuoc * 4.4 - 11;
            if (soThue[i] < 0){
                soThue[i] = 0.0;
            }
                
        }
        if (bhyt = 0)
        {
            soThue[i] = luong[i] - nguoiPhuThuoc * 4.4 - 11 - luong[i] * 10.5 / 100;
            if (soThue[i] < 0){
                soThue[i] = 0.0;
            }
            
        }
        tongSoThue = tongSoThue + soThue[i];
    }
    for (int i = 1; i <= 12; i++)
    {
        if (soThue[i] < 0)
        {
            cout << " Ban khong can dong thue"<<endl;
        }
        else
        {   
            
            if (soThue[i] <= 5)
            {
                phaiNop[i] = soThue[i] * 5 / 100;
            }
            else if (soThue[i] <= 10)
            {
                phaiNop[i] = 0.25 + (soThue[i] - 5) * 10 / 100;
            }
            else if (soThue[i] <= 18)
            {
                phaiNop[i] = 0.75 + (soThue[i] - 10) * 15 / 100;
            }
            else if (soThue[i] <= 32)
            {
                phaiNop[i] = 1.95 + (soThue[i] - 18) * 20 / 100;
            }
            else if (soThue[i] <= 52)
            {
                phaiNop[i] = 4.75 + (soThue[i] - 32) * 25 / 100;
            }
            else if (soThue[i] <= 80)
            {
                phaiNop[i] = 9.75 + (soThue[i] - 52) * 30 / 100;
            }
            else
            {
                phaiNop[i]= 18.15 + (soThue[i] - 80) * 35 / 100;
            }
        }
        tongDaNop = tongDaNop + phaiNop[i];
    }
    if(tongSoThue<=0){
        tongCanNop=0;
    }else{
        if(tongSoThue <= 60){
            tongCanNop =tongSoThue*5/100;
        }
        else if(tongSoThue<=120){
            tongCanNop = 60*5/100 +(tongSoThue-60)*10/100;
        }
        else if(tongSoThue<=216){
            tongCanNop = 60*5/100 +60*10/100 +(tongSoThue-120)*15/100;
        }
        else if(tongSoThue<=384){
            tongCanNop = 60*5/100 +60*10/100 +96*15/100 +(tongSoThue-216)*20/100;
        }
        else if(tongSoThue<=624){
            tongCanNop = 60*5/100 +60*10/100 +96*15/100 +168*20/100+ (tongSoThue-384)*25/100;
        }
        else if(tongSoThue<=960){
            tongCanNop = 60*5/100 +60*10/100 +96*15/100 +168*20/100+ 240*25/100 +(tongSoThue-624)*30/100;
        }else{
            tongCanNop = 60*5/100 +60*10/100 +96*15/100 +168*20/100+ 240*25/100 +336*30/100 + (tongSoThue-960)*35/100;
        }
    }
    cout<<setw(6)<<"thang" << setw(15)<<"luong"<<setw(20)<<"thu nhap tinh thue"<< right <<setw(17)<<"So tien phai nop"<<endl;
    for(int i=1; i<=12; i++){
        cout<<setw(6)<<i<< setw(15)<<luong[i]<<setw(20)<<soThue[i]<< right <<setw(17)<<phaiNop[i]<<endl;
    }
    cout<<" Tong luong: "<<tongLuong<<endl;
    cout<<" Thu nhap tinh thue ca nam: "<<tongSoThue<<endl;
    cout<<" Tong da nop: "<<tongDaNop<<endl;
    cout<<" Tong can nop: "<<tongCanNop<<endl;
    cout<<" Tien thue thua: "<< tongDaNop- tongCanNop<<endl;
    return 0;
}