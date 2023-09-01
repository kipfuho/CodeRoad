// unefficient branching method
#include<bits/stdc++.h>
#include<vector>

#define ll long long
#define ull unsigned long long
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define FOD(i,r,l) for(int i=r;i>=l;i--)

using namespace std;

int const nmax=1e3+1;
int n, minx=10e8, ideal=10e8;

vector<int> c[nmax]; //Expense Matrix
int visited[nmax];
int trace[nmax];

void retrace(int start){
    FOR(i,1,n){
        cout<<trace[start]+1<<" ";
        start=trace[start];
    }
    cout<<endl;
}

void sol(int from, int start, int time, int r){
	if(time==n){
		int f=r+c[start][from];	
		if(ideal>f){
            trace[start]=from;
			ideal=f;
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(visited[i]==1 || i==start) continue;
        int t=trace[start];
		visited[i]=1;
		int g=r+c[start][i]+(n-time)*minx;
		if(g<ideal){
            int fcur=ideal;
            trace[start]=i;
            sol(from, i, time+1, r+c[start][i]);
            if(fcur==ideal) trace[start]=t;
        }
		visited[i]=0;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,0,n-1){
		FOR(j,0,n-1){
			int t;
			cin>>t;
			c[i].push_back(t);
			if(minx>t && t>0) minx=t;
		}
	}
	fill_n(visited,n,0);
    fill_n(trace,n,0);
	cout<<"Starting point(1->n): "<<endl;
    int S; cin>>S;
    visited[S-1]=1;
	sol(S-1,S-1,1,0);
	cout<<"Min expense: "<<ideal<<endl;
    cout<<"Path: "<<S<<" ";
    retrace(S-1);
}