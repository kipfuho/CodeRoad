
//   https://leetcode.com/problems/shortest-path-visiting-all-nodes


class Solution {
public:
    class tuple{
        public:
        int node;
        int mask;
        int cost;
        tuple(int node, int mask, int cost){
            this-> node = node;
            this-> mask = mask;
            this-> cost = cost;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<pair<int, int>> vis;
        queue<tuple> q;
        int all = (1<<n) - 1;
        for(int i = 0; i < n; i++){
            int Mask = 1<<i;
            tuple NewTuple(i, Mask, 0);
            q.push(NewTuple);
            vis.insert({i, Mask});
        }
        while(!q.empty()){
            tuple curr = q.front();
            q.pop();

            if(curr.mask == all) return curr.cost;

            for(auto& adj:graph[curr.node]){
                int mask = curr.mask | (1<<adj);
                tuple NewTuple(adj, mask, curr.cost + 1);
                if(vis.find({adj, mask}) == vis.end()){
                    q.push(NewTuple);
                    vis.insert({adj, mask});
                }
            }
        }
        return -1;
    }
};