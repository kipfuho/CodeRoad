// Nguyen Dinh Ut Biu
// Bài 4.9. Cài dat thuat toán Dijkstra trên do thi vô huong
// duoc bieu dien bang danh sách ke su dung std::priority_queue

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{// kieu du lieu de luu dinh u và do dài cua duong di ngan nhat tu s den u.
    int u;
    long long Dist_u;
};

// Kieu du lieu dung de so sanh 2 Node
struct cmp{
    bool operator() (Node a, Node b) {
        return a.Dist_u > b.Dist_u;
    }
};

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
	// Khai bao mot so bien
    priority_queue<Node, vector<Node>, cmp> minqueue;
    vector<bool> visited;
    vector<int> distance;
    visited.resize(adj.size(), false);
    distance.resize(adj.size(), INT_MAX);
    // Bat dau tu dinh 0
    distance[0] = 0;
    minqueue.push({0, 0});
    while(!minqueue.empty()){
    	// lay top ra khoi priority queue
        Node top = minqueue.top();
        minqueue.pop();
        
        int u = top.u;
        if(visited[u] == true) continue;
        
        // duyet cac canh ke voi u
        for(auto& edge:adj[u]){
            int v = edge.first, w = edge.second;
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u] + w;
                minqueue.push({v, distance[v]});
            }
        }
    }
    
    return distance;
}

int main() {
    int n, m;
    cin >> n >> m;
	vector< vector< pair<int, int> > > adj(n);
	auto add_edge = [&adj] (int u, int v, int w) {
	    adj[u].push_back({v, w});
	    adj[v].push_back({u, w});
	};
	
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(u, v, w);
	}
	
	vector<int> distance = dijkstra(adj);
	for (unsigned int i = 0; i < distance.size(); ++i) {
    	cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
	}
}
