/*
Hiện tại giá điện đang được tính theo bậc thang gồm 6 mức (mức điều chỉnh từ 04/05/2023), với giá thấp nhất (bậc 1) là 1.728VND và giá bậc cao nhất là 3.015 VND. Tuy nhiên EVN đang đề xuất một cách tính giá điện bậc thang mới chỉ gồm 5 mức như hinh dưới, giá thấp nhất (bậc 1) khoảng 1.728 đồng một kWh và cao nhất (bậc 5) là 3.457 đồng một kWh. 

Bậc	Biểu giá hiện hành	Phương án 5 bậc
  	Mức sử dụng	Giá (*)	Mức sử dụng	Giá
1	0-50 kWh	1.728	0-100 kWh	1.728
2	51-100 kWh	1.786	101-200 kWh	2.074
3	101-200 kWh	2.074	201-400 kWh	2.612
4	201-300 kWh	2.612	401-700 kWh	3.111
5	301-400 kWh	2.919	701 kWh trở lên	3.457
6  	401 kWh trở lên	3.015		
(*) Giá chưa bao gồm thuế VAT

Hãy xây dựng chương trình nhập vào số kwh điện của một hộ tiêu thụ và so sánh xem theo bảng giá mới đang lấy ý kiến thì tiền điện tiêu thụ của hộ đó sẽ tăng thêm hay giảm đi bao nhiêu.

INPUT: là số kwh điện tiêu thụ của hộ (là số nguyên)
OUTPUT: là chênh lệch giữa giá theo đề xuất và giá theo mô hình bậc thang 6 mức đang được áp dụng.

VAT sẽ được lấy là 10%, và kết quả in ra sẽ lấy tới 2 chữ số thập phân

EXAMPLE 
INPUT
540
OUTPUT
-22176.00


INPUT
70
OUTPUT
-1276.00

*/

#include <bits/stdc++.h> 

using namespace std;

int main() 
{ 
    int n; cin >> n;
    double oldP = 0, newP = 0;
    double ePrice[2][6] = {{1728, 1786, 2074, 2612, 2919, 3015}, {1728, 2074, 2612, 3111, 3457, 0}};
    oldP += min(50, n)*ePrice[0][0];
    if(n > 50) oldP += min(50, n - 50)*ePrice[0][1];
    if(n > 100) oldP += min(100, n - 100)*ePrice[0][2];
    if(n > 200) oldP += min(100, n - 200)*ePrice[0][3];
    if(n > 300) oldP += min(100, n - 300)*ePrice[0][4];
    if(n > 400) oldP += (n - 400)*ePrice[0][5];

    newP += min(100, n)*ePrice[1][0];
    if(n > 100) newP += min(100, n - 100)*ePrice[1][1];
    if(n > 200) newP += min(200, n - 200)*ePrice[1][2];
    if(n > 400) newP += min(300, n - 400)*ePrice[1][3];
    if(n > 700) newP += (n - 700)*ePrice[1][4];

    printf("%.2lf", (newP - oldP)*1.1);
}