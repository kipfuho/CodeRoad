// https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> mp;
        int total = 0;
        for(auto& x:nums){
            if(mp[x]){
                total += mp[x]++;
            }
            else{
                mp[x] = 1;
            }
        }
        return total;
    }
};