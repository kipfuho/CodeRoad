// Nguyen Dinh Ut Biu 20215317
// Bai3.9: Một y tá cần lập lịch làm việc trong N ngày, mỗi ngày chỉ có thể là 
// làm việc hay nghỉ ngơi. Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào 
// liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc đoạn 
// [K1,K2]. Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một 
// dòng một xâu nhị phân độ dài n với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu 
// phải được in ra theo thứ tự từ điển

#include<iostream>
#include<vector>

using namespace std;

int n, k1, k2, total_res = 0;
vector<int> res;

void input(){
	cin >> n >> k1 >> k2;
	res.resize(n + 1);
}

// In ket qua 
void print_res(){
	for(int i = 1; i <= n; i++){
		cout << res[i];
	}
	cout << endl;
}

//#Exhaustive recursive function
// L represent current consecutive working days, if L = 0 then i_th day is a rest day
// else if L > 0 then i_th day is a woirking day
void TRY(int i, int L){
	// i == n -> check and print current solution
	if(i == n){
		// L = 0 -> last bit is 0 -> always a good schedule
		if(L == 0){
			res[i] = 0;
			total_res++;
		}
		// else last bit is 1, we need to check if consecutive working days is between k1 and k2
		else if(L >= k1){
			res[i] = 1;
			total_res++;
		}
		return;
	}
	
	// current bit is 0, try with next bit is 1
	if(L == 0){
		// Check if we should continue the recursion
		// Here if k1 > n - i last bit then obviously we can't
		// make a schedule with all consecutive working days >= k1
		if(n - i < k1) return;
		
		res[i] = 0;
		TRY(i + 1, 1);
	}
	// current bit is 1, we divide (i+1)_th bit to 3 sceneries
	else{
		res[i] = 1;
		if(L < k1){
			TRY(i + 1, L + 1);
		}
		else if(L == k2){
			TRY(i + 1, 0);
		}
		else{
			TRY(i + 1, 0);
			TRY(i + 1, L + 1);
		}
	}
}

// Khu de quy
void sol(){
	cout << "Stack? Worthless";
}

int main(){
	input();
	TRY(1, 0);
	TRY(1, 1);
	cout << total_res;
}
