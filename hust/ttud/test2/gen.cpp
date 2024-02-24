//

#include<bits/stdc++.h>
#define _ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define FOD(i, r, l) for(int i = r; i >= l; i--)
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define bit(x) (x & (-x))

using namespace std;

std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<> gen_num(-100'000,100'000);
std::uniform_int_distribution<std::mt19937::result_type> gen_natural(1,100'000);

void prob1(){
    return;
}

void prob2(){
	string queries[4] = {"?number_points", "?number_segments", "?connected_components", "?longest_cycle_from"};
	map<pii, bool> exist_pair;
	int u, v, n = gen_natural(rng), m = gen_natural(rng), p = gen_natural(rng);
	std::uniform_int_distribution<std::mt19937::result_type> gen_point(1, n), gen_query(0, 3);
	
	FOR(i, 1, n){
		cout  << "P" << i << " " << gen_num(rng) << " " << gen_num(rng) << "\n";
	}
	cout << "#\n";
	FOR(i, 1, m){
		do{
			u = gen_point(rng), v = gen_point(rng);
		} while(exist_pair[{u, v}]);

		exist_pair[{u, v}] = true;
		cout  << "S" << i << " P" << u << " P" << v << "\n";
	}
	cout << "#\n";
	FOR(i, 1, p){
		u = gen_query(rng);
		if(u == 3){
			int v = gen_point(rng);
			cout << queries[u] << " P" << v << "\n";
		}
		else{
			cout << queries[u] << "\n";
		}
	}
	cout << "###\n";
    return;
}

void prob3(){
    return;
}

int main(){_
    freopen("in.txt", "w", stdout);
    int t; cin >> t;
    if(t == 1){
		prob1();
	}
	else if(t == 2){
		prob2();
	}
	else if(t == 3){
		prob3();
	}
    return 0;
}