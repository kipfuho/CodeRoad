// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> minL(n);
        stack<int> st;
        minL[0] = INT_MAX;
        for(int i = 1; i < n; i++) minL[i] = min(minL[i-1], nums[i-1]);
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > minL[i]){
                while(!st.empty() && st.top() <= minL[i]){
                    st.pop();
                }
                if(!st.empty() && st.top() < nums[i]) return true;
            }
            st.push(nums[i]);
        }
        return false;
    }
};