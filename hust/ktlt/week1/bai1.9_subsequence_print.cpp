// Nguyễn Đình Út Biu - 20215317
/*
Bài tập 1.9: Viết chương trình in ra tất cả các dãy con của một dãy cho trước.

Dữ liệu vào:
Dòng đầu tiên chứ số n là số lượng phần tử của dãy.
Dòng tiếp theo chứa n số nguyên cách nhau bởi dấu cách là các phần tử của dãy.

Kết quả:
In ra các dãy con của dãy trên, mỗi dãy con in trên một dòng.
*/

#include<iostream>

using namespace std;

int n;

// Hàm thử các trường hợp dãy con bắt đầu từ chỉ số start, với kích thước size
void TRY(int arr[], int start, int size){
    // Đã hết trường hợp
    if(start == n) return;
    // Khi size lớn hơn số phần tử của mảng con đang xét, chuyển sang thử tại vị trí start + 1
    if(size == (n - start + 1)){
        TRY(arr, start + 1, 1);
        return;
    }
    for(int i = start; i < size + start; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    TRY(arr, start, size + 1);
}

int main(){
    // Tạo dãy
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    // Bắt đầu thử từ phần tử đầu, với kích thước 1
    TRY(arr, 0, 1);
}