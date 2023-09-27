

//  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> solNumber;
        int index = 0;
        for(auto& x:mat){
            int counter = 0;
            for(auto& y:x) counter+=y;
            solNumber.push_back({index++, counter});
        }
        sort(solNumber.begin(), solNumber.end(), [](auto& left, auto& right)
        {
            if(left.second < right.second) return true;
            else if(left.second == right.second){
                if(left.first < right.first) return true;
                else return false;
            } 
            else return false;
        });
        vector<int> res;
        for(auto& x:solNumber){
            if(k-- == 0) break;
            res.push_back(x.first);
        }
        return res;
    }
};