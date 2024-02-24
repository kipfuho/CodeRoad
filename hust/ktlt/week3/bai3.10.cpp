// Nguyen Dinh Ut Biu 20215317
// Bai 3.10: Khoang cách Hamming giua hai xâu cùng do dài 
// là so vi trí mà ký tu tai vi trí dó là khác nhau trên hai 
// xâu. Cho S là xâu gom n ký tu 0. Hãy li?t kê t?t c? các 
// xâu nh? phân d? dài n, có khoang cách Hamming voi S
// bang H. Các xâu phai duoc liet kê theo thu tu tu dien

#include<iostream>

using namespace std;

// n: string length, h: hamming distance
// L_END: number of bit 1 at the start of hamming string ie: L_END = 2 if 110000101010
// C: the potential index for swap_reset
// res store the bit of hamming string
int n, h, L_END, C;
int res[10001];

void input(){
	cin >> n >> h;
	// set h bit 1 to the end of hamming string
	for(int i = 1; i <= h; i++) res[i] = 1;
	for(int i = h + 1; i <= n; i++) res[i] = 0;
	// if n == h we will set end_condition for while_loop to true
	if(n == h) L_END = h;
	else L_END = 0;
	// first potential index for swap
	C = h;
}

// reverse print
void print_res(){
	for(int i = n; i != 0; i--){
		cout << res[i];
	}
	cout << endl;
}

// swap bit of i_th and j_th index
// we know that i < j and j is always 0
void swap_reset(int i, int j){
	if(j == n - L_END){
		L_END++;
	}
	res[i] = 0;
	res[j] = 1;
	// now we need to reset left_remain bit to the start of res
	// while also calculating C
	int k = 1;
	while(res[k] == 0 && i > k){
		if(res[--i]){
			res[k++] = 1;
			res[i] = 0;
		}
		C--;
	}
	// find the first bit 1 with bit 0 come before it
	if(C == 1){
		while(res[C] == 0) C++;
		while(res[C] == 1) C++;
	}
	// offset
	C--;
}

int main(){
	int t; cin >> t;
	while(t--){
		input();
		while (L_END != h){
			print_res();
			swap_reset(C, C + 1);
		}
		print_res();
	}	
}
