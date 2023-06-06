// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.7. Viết hàm tính tổng các phần tử trong hai mảng.
Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực
*/


#include <iostream>
using namespace std;

// Hàm tính tổng 2 mảng dùng template
template <typename T> 
T arr_sum(T *a, int n1, T *b, int n2){
    T sum = 0;
    for(int i = 0; i < n1; i++){
        sum += a[i];
    }
    for(int i = 0; i < n2; i++){
        sum += b[i];
    }
    return sum;
}

int main() {
    int val;
    cin >> val;
    
    {
        // arr_sum cho 2 mảng số nguyên
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        // arr_sum cho 2 mảng số thực
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}