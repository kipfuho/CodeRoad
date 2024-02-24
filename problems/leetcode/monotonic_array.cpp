// https://leetcode.com/problems/monotonic-array/
 
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int count = 0, offset = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) count++;
            else if(nums[i] < nums[i-1]) count--;
            else offset++;
        }
        count = abs(count);
        if(count + offset != n) return false;
        return true;
    }
};