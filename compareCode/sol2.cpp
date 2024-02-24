#include <bits/stdc++.h>
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


/*

void sol2(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    while(m--){
        int l, r; cin >> l >> r;
        int max = 0, sum = 0;
        for(int i = 0; i < l - 1; i++){ 
            if(s[i] == '+') sum++;
            else sum--;
            if(abs(sum) > max) max = abs(sum);
        }
        for(int i = r; i < n; i++){
            if(s[i] == '+') sum++;
            else sum--;
            if(abs(sum) > max) max = abs(sum);
        }
        cout << abs(max) + 1 << endl;
    }
}

void sol(){
    int n; cin >> n;
    long long temp, prev = 0;
    long long total = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        cout << temp << " ";
        if(temp >= prev){
            prev = temp;
            continue;
        }
        else{
            cout << endl;
            while(prev > temp){
                total++;
                temp = temp + temp;
            }
            prev = temp;
        }
    }
    cout << total << endl;
}

/*
 * 1282. Fibonaci Words
 * TOPIC: dp
 * status: Accepted
 

using namespace std;
#define N 0x80
#define M (1<<17)
#define oo 0xfffffffful
#define INF 0xffffffffffffffffull
typedef long long i64;
typedef unsigned long long u64;

int n,m;
i64 pref[N],ones[N],q[M];
char t[M];
unsigned int s[N][M],p[N][M];
u64 len[N],z[N];
map<pair<int,int>,bool> mp;

bool is_equal( int n, int i, int j ) {
	if ( len[n] != j-i+1 ) return false ;
	if ( n == 0 || n == 1 )
		return t[i]==n+'0';
	
	//if ( mp.find(make_pair(n,i)) != mp.end() )
	//	return mp[make_pair(n,i)];
	//return mp[make_pair(n,i)] = is_equal(n-1,i,i+len[n-1]-1) && is_equal(n-2,i+len[n-1],j);
	return ones[n]==q[j]-(i==0?0:q[i-1]) && is_equal(n-1,i,i+len[n-1]-1) && is_equal(n-2,i+len[n-1],j);
}

unsigned int calc_s( int n, int k ) {
	if ( s[n][k] < +oo )
		return s[n][k];
	if ( len[n] < k ) return s[n][k] = 0;
	if ( n <= 1 )
		return s[n][k] = t[0]=='0'+n;
	if ( len[n-2] >= k ) 
		return s[n][k] = calc_s(n-2,k);
	return s[n][k] = calc_s(n-1,k-len[n-2])*is_equal(n-2,k-len[n-2],k-1);
}

unsigned int calc_p( int n, int k ) {
	if ( p[n][k] < +oo )
		return p[n][k];
	if ( len[n] < k ) return p[n][k] = 0;
	if ( n <= 1 )
		return p[n][k] = t[m-1]=='0'+n;
	if ( len[n-1] >= k )
		return p[n][k] = calc_p(n-1,k);
	return p[n][k] = is_equal(n-1,m-k,m-k+len[n-1]-1)*calc_p(n-2,k-len[n-1]);
}

u64 calc_z( int n ) {
	int k;
	if ( z[n] < INF )
		return z[n];
	if ( n <= 1 )
		return z[n] = calc_s(n,m);
	for ( z[n] = calc_z(n-1)+calc_z(n-2), k = 1; k <= m-1; ++k )
		z[n] += calc_s(n-1,k)*calc_p(n-2,m-k);
	return z[n];
}

int sol3() {
	int i,j,k,cs = 0;
	for ( len[0]=len[1]=1,pref[1]=1,ones[1]=1,i=2;i<N;len[i]=len[i-1]+len[i-2],ones[i]=ones[i-1]+ones[i-2],pref[i]=pref[i-1]+ones[i],++i );
	while ( 2 == scanf("%d %s",&n,t) ) {
		mp.clear(), m = strlen(t), memset(s,0xff,sizeof s), memset(p,0xff,sizeof p), memset(z,0xff,sizeof z);
		for ( q[0] = (t[0]=='1')?1:0, i = 1; i < m; ++i ) q[i] = q[i-1]+(t[i]=='1'?1:0);
		printf("Case %d: %llu\n",++cs,calc_z(n));
	}
	return 0;
}


int sol4(){
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        vector<long long> arr(n+1), visit(n+1, 0);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        long long sum = 0;
        int min_i;
        bool valid = false;
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                if((arr[i] + arr[j]) >= i*j*c){
                    min_i = min(i, j);
                    visit[i] = 1;
                    visit[j] = 1;
                    sum = arr[i] + arr[j];
                    valid = true;
                    break;
                }
            }
            if(valid) break;
        }
        if(!valid){
            cout << "No\n";
        }
        else{
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(visit[j]) continue;
                    if(sum + arr[j] >= min_i*j*c){
                        sum += arr[j];
                        visit[j] = 1;
                        min_i = min(min_i, j);
                    }
                }
            }

            valid = true;
            for(int i = 1; i <= n; i++){
                if(!visit[i]){
                    valid = false;
                    break;
                }
            }
            if(valid) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}

*/

int n, l1, l2, maxshift, arr[1000001], dp[1000001];
queue<pair<int, int>> q;
pair<int, int> curpair;

int sol5(){_
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n >> l1 >> l2;
    maxshift = l2 - l1;
    FOR(i, 1, n) cin >> arr[i];

    dp[1] = arr[1];
    curpair = {arr[1], 1};
    FOR(i, 2, l1){
        if(curpair.first > arr[i] && maxshift >= (i - curpair.second)){
            dp[i] = curpair.first;
            q.push({arr[i], i});
        }
        else{
            while(!q.empty()){
                curpair = q.front();
                q.pop();
                if(curpair.first > arr[i]) break;
            }
            if(curpair.first <= arr[i]){
                curpair = {arr[i], i};
            }
            dp[i] = curpair.first;
        }
    }
    FOR(i, l1 + 1, n){
        if(curpair.first > (dp[i - l1] + arr[i]) && maxshift >= (i - curpair.second)){
            dp[i] = curpair.first;
            q.push({dp[i], i});
        }
        else{
            while(!q.empty()){
                curpair = q.front();
                q.pop();
                if(curpair.first > (dp[i - l1] + arr[i])) break;
            }
            if(curpair.first <= (dp[i - l1] + arr[i])){
                curpair = {(dp[i - l1] + arr[i]), i};
            }
            dp[i] = curpair.first;
        }
    }
    int maximum = arr[1];
    FOR(i, 1, n) maximum = max(maximum, dp[i]);
    cout << maximum;
    return 0;
}

int main(int argc, char** argv) {
    freopen("input.inp", "r", stdin);
    freopen("sol2.out", "w", stdout);
    sol5();
}