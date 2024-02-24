/*
Description
Given an undirected graph on the plane, each node (point) has a coordinate. Between the points, there are segments (edges) connecting pairs of two points. Perform a sequence of queries of the following types:
?number_points: return the number of points (or nodes) of the graph 
?number_segments: return the number of segments (or edges) of the graph 
?connected_components: return the number of connected_components of the graph 
?longest_cycle_from <PointID>: return the number of edges of the longest cycle (the length of the cycle is measured in term of the number of edges of the cycle) starting from point <PointID> visiting other points (each point is visited exactly once) and terminating at the point <PointID>

Input
The first block is a sequence of lines, each line contains the information of a point with the following format:
                  <PointID> <x_coordinate> <y_coordinate>
<PointID>: string of length from 2 to 7 representing the identifer of the point 
<x_coordinate>, <y_coordinate>: integers representing the coordinates of the point 
The first block is terminated by a line containing #
The second block is a sequence of lines, each line is the information about a segment with the following format:
                    <SegmentID> <PointID1> <PointID2>
<SegmentID>: string of length from 2 to 7 representing the identifer of the segment 
<PointID1>, <PointID2>: String representing identifiers of the 2 points of the segment 
The second block is terminated by  a line containing #
The third block is a sequence of lines, each line is a query of types described above. The third block is terminated by a line containing ###

Output
Write in each line the result of the corresponding query 

Example
Input 
P01 0 0
P02 0 1
P03 0 2
P04 1 0
P05 1 1
P06 1 2
P07 2 0
P08 2 1
P09 2 2
#
S01 P01 P02 
S02 P02 P03 
S03 P04 P05 
S04 P05 P06 
S05 P07 P08 
S06 P08 P09 
S07 P01 P04 
S08 P04 P07 
S09 P02 P05 
S10 P05 P08 
S11 P03 P06 
S12 P06 P09 
#
?number_points
?number_segments
?connected_components
?longest_cycle_from P01
###

Output 
9
12
1
8
*/

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

vector< vector<int> > g;
int points[100001];
bool visited[100001];

int get_num(string s){
	int num1, num2;
	sscanf(s.c_str(), "%c%d", &num1, &num2);
	return num2%100001;
}

void dfs(int u){
	for(int v:g[u]){
		if(!visited[v]){
			visited[v] = true;
			dfs(v);
		}
	}
	return;
}

int dfs2(int u, int ori, int length){
	int res = 0;
	for(int v:g[u]){
		if(v == ori){
			res = max(res, length + 1);
		}
		else if(!visited[v]){
			visited[v] = true;
			res = max(res, dfs2(v, ori, length + 1));
			visited[v] = false;
		}
	}
	return res;
}

int main(){_
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(visited, false, 100001);
	memset(points, 0, 4*100001);
	int cnt = 0, edges = 0, cc = 0;
	string token;
	while(cin >> token){
		if(token == "#") break;
		int num = get_num(token);
		points[num] = ++cnt;
		int x, y; cin >> x >> y;
	}
	g.resize(cnt+2, vector<int>());
	while(cin >> token){
		if(token == "#") break;
		int p1, p2;
		cin >> token; p1 = get_num(token);
		cin >> token; p2 = get_num(token);
		g[points[p1]].push_back(points[p2]);
		g[points[p2]].push_back(points[p1]);
		edges++;
	}
	for(int i = 1; i <= cnt; i++){
		if(!visited[i]){
			cc++;
			visited[i] = true;
			dfs(i);
		}
	}
	while(cin >> token){
		if(token == "###") break; 
		if(token == "?number_points") cout << cnt << "\n";
		else if(token == "?number_segments") cout << edges << "\n";
		else if(token == "?connected_components") cout << cc << "\n";
		else{
			cin >> token;
			int ori = points[get_num(token)];
			memset(visited, 0, cnt + 1);
			visited[ori] = true;
			cout << "-1\n";
		}
	}
}