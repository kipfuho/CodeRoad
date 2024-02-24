/*
Description
Một công ty sữa muốn tri ân khách hàng, công ty in vào mỗi hộp sữa tươi một số tự nhiên được lấy từ một danh sách các số tự nhiên bí mật khác nhau cho trước. Người tiêu dùng nếu như thu thập một tập các hộp sữa tươi sao cho các số tự nhiên trong các hộp sữa này khác nhau và tổng của chúng lớn hơn hoặc bằng năm thành lập công ty và chia hết cho 5 thì sẽ được tặng thêm 1 hộp sữa tươi. Hỏi có bao nhiêu cách khác nhau có thể đổi được quà. Hai cách được gọi là khác nhau, nếu tập hợp các số tự nhiên trên các hộp sữa là khác nhau.
Dữ liệu
· Dòng 1: Chứa 1 số nguyên n ( 1 <= n <= 20) số lượng phần tử trong danh sách số tự nhiên bí mật
· Dòng 2: Chứa n số tự nhiên, cách nhau bởi dấu cách, có giá trị nhỏ hơn 2000, là các số tự nhiên bí mật in trên các hộp sữa;
· Dòng 3: Chứa 1 số tự nhiên là năm thành lập công ty, số này có giá trị nhỏ hơn 2023;
Kết quả
· Một số tự nhiên duy nhất là số lượng các cách khác nhau thu thập các tập số trên các hộp sữa tươi có thể đổi được quà.
Ví dụ
Đầu vào
4
1000 1600 101 200
1901
Đầu ra
2
Giải thích ví dụ: Kết quả bằng 2, vì có 2 tập hợp thỏa mãn tổng các phần tử ít nhất 1901 và chia hết cho 5 là {1000, 1600} và  {1000, 1600, 200}.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, arr[21];
bool visited[21];
set<vector<int>> st;

void TRY(int i, int sum, bool mode, vector<int> cur){
	bool conf = true;
	if(sum > m && sum%5 == 0){
		conf = false;
		st.insert(cur);
	}
	if(i >= n) return;
	TRY(i+1, sum, conf, cur);
	sum+=arr[i];
	cur.push_back(arr[i]);
	TRY(i+1, sum, true, cur);
	return;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	int res = 0;
	TRY(0, 0, true, vector<int>());
	cout << st.size();
	return 0;
}