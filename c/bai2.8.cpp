// Nguyễn Đình Út Biu - 20215317
/*
Bài 2.8. Viết hàm so sánh cho thuật toán sắp xếp. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    // Hàm nặc danh lambda so sánh tổng 2 vector con của vector a
    auto func = [&a](vector<int> arr1, vector<int> arr2){
        int sum1 = 0, sum2 = 0;
        for(auto& x : arr1){
            sum1 += x;
        }
        for(auto& x : arr2){
            sum2 += x;
        }
        if(sum1 > sum2) return true;
        return false;
    };
    // Sắp xếp sử dụng hàm có sẵn trong thư viện algorithm, dùng func làm hàm so sánh
    sort(a.begin(), a.end(), func);

    // In các vector của a theo dòng
    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }

    return 0;
}