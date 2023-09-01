#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

vector<int> x = {1,2,3,4,5,6};
vector<int> y = {2,4,6,8,10,12};
int min(int x, int y){
	return x > y ? y : x;
}
int X(int n);
int Y(int n);
int Sum1(int n);
int Sum2(int n);

int main(){
	int n; cin >> n;
	cout << Sum1(n - 1) << endl;
	cout << Sum2(n - 1);
}

int X(int n){
	if(n < 6) return x[n];
	return X(n-6) - Y(n - 4) + X(n - 3) + Y(n - 2);
}

int Y(int n){
	if(n < 6) return y[n];
	return Y(n - 6) - X(n - 5) + Y(n - 2) + X(n - 1);
}

int Sum1(int n){
	clock_t start = clock();
	int SUM = 0;
	for(int i = 0; i <= n; i++){
		SUM += X(i) + Y(i);
	}
	clock_t end = clock();
	double TIME = double(end - start) / CLOCKS_PER_SEC;
	cout << "Time Sum1: " << TIME << endl;
	return SUM;
}

int Sum2(int n){
	clock_t start = clock();
	int SUM = 0, Xi, Yi;
	for(int i = 0; i <= min(n, 5); i++){
		SUM += x[i] + y[i];
	}
	if(n > 5){
		for(int i = 6; i <= n; i++){
			Xi = x[i - 6] - y[i - 4] + x[i - 3] + y[i - 2];
			Yi = y[i - 6] - x[i - 5] + y[i - 2] + x[i - 1];
			x.push_back(Xi);
			y.push_back(Yi);
			SUM += Xi + Yi;
		}
	}
	clock_t end = clock();
	double TIME = double(end - start) / CLOCKS_PER_SEC;
	cout << "Time Sum2: " << TIME << endl;
	return SUM;
}
