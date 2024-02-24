// Nguyen Dinh Ut Biu 20215317
// Bai3.11: Superior l� mot h�n dao tuyet dep voi n
// dia diem chup anh v� c�c duong mot chieu noi c�c diem chup anh voi nhau. 
// �o�n kh�ch tham quan c� r nguoi voi so th�ch chuop anh kh�c nhau. Theo d�, 
// moi nguoi se dua ra danh s�ch c�c dia diem m� ho muon chup. Ban can gi�p 
// moi nguoi trong do�n lap lich di chuyen sao cho di qua c�c diem ho y�u 
// cau d�ng mot lan, kh�ng di qua diem n�o kh�c, bat dau tai diem dau ti�n 
// v� ket th�c tai diem cuoi c�ng trong danh s�ch m� ho dua ra, v� c� tong 
// khoang c�ch di lai l� nho nhat.

#include<iostream>
#include<string>
#include<vector>

using namespace std;

// n: number of picture sites
// m: number of picture sites for each photographer
// r: number of photographers
// curr: current smallest expense
// best: current best expense to travel all sites of current photographer
// cmin: smallest expense between 2 sites
// c: expense matrix
// mark: array to mark visited sites
// from: array to store previous site
// path: vector store sites for current photographer
int n, m, r, curr, best, cmin = INT_MAX;
int c[10001][10001];
int mark[10001];
int from[10001];
vector<int> path;

// get basic input and set cmin
void input(){
	cin >> n >> r;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int t;
			cin >> t;
			c[i][j] = t;
			if(t != 0 && t < cmin) cmin = t;
		}
	}
}

// split line to get favoured sites of one photographer
// also reset and set data 
void prepare(string s){
	string temp = "";
	path.clear();
	for(int i = 0; i < s.size(); i++){
		if(s[i] == ' ' && temp.size() > 0){
			path.push_back(stoi(temp));
			temp = "";
		}
		else{
			temp += s[i];
		}
	}
	if(temp.size() > 0) path.push_back(stoi(temp));
	m = path.size() - 1;
	for(int i = 2; i <= m; i++) from[i] = 0;
	for(int i = 1; i <= n; i++) mark[i] = 0;
	from[2] = path[0];
	mark[path[0]] = 1;
	curr = 0;
	best = INT_MAX;
}

// recursive function to calculate best
void TRY(int k){
	int site1 = from[k];
    for(int i = 1; i < m; i++){
    	// check if current site is already visited
    	int site2 = path[i];
    	int expense = c[site1][site2];
        if(mark[site2] == 0 && expense != 0){
        	// check if we should continue in this branch
        	curr += expense;
        	if(curr + (m - k + 1)*cmin > best ){
                curr -= expense;
                continue;
            }
            
            mark[site2] = 1;
        	from[k + 1] = site2;
        	
            // last destination, check if we can update best
            if(k == m){
            	int lastSite = path[m];
            	int tmp = c[site2][lastSite];
            	if(tmp != 0){
                	if(curr + tmp < best){
                		best = curr + tmp;
                		mark[lastSite] = 1;
					}
				}
            }
            else TRY(k + 1);
            
            // uncheck current site and continue
            mark[site2] = 0;
            curr -= expense;
        }
    }
}

int main(){
	input();
	while (cin.get() != '\n') 
	{
	    continue;
	}
	while(r--){
		string s;
		getline(cin, s);
		prepare(s);
		TRY(2);
		if(mark[path[m]]) cout << best;
		else cout << 0;
		cout << endl;
	}
}

