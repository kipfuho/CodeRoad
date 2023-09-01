// Cau lenh dich: g++ -o bai1_21010644.exe bai1_21010644.cpp

#include<iostream>

using namespace std;

string getWinner(string p1, string p2){
	if(p1.size() != p2.size()) return "Error";
	
	int p1s = 0, p2s = 0;
	for(int i = 0; i < p1.size(); i++){
		// TH nguoi 1 thang
			 if(p1[i] == 'B' && p2[i] == 'K') p1s++;
		else if(p1[i] == 'K' && p2[i] == 'G') p1s++;
		else if(p1[i] == 'G' && p2[i] == 'B') p1s++;
		// TH nguoi 2 thang
		else if(p2[i] == 'B' && p1[i] == 'K') p2s++;
		else if(p2[i] == 'K' && p1[i] == 'G') p2s++;
		else if(p2[i] == 'G' && p1[i] == 'B') p2s++;
		// TH hoa
		else if(p2[i] == 'G' && p1[i] == 'G') continue;
		else if(p2[i] == 'B' && p1[i] == 'B') continue;
		else if(p2[i] == 'K' && p1[i] == 'K') continue;
		// input error
		else return "Error";
	}
	
	if(p1s > p1s) return "A";
	else if(p2s > p1s) return "B";
	return "Hoa";
}

int main(){
	string p1, p2;
	cin >> p1 >> p2;
	cout << getWinner(p1, p2);
}
