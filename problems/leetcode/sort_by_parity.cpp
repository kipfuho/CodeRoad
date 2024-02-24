// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(r > l){
            if(nums[r]&1) r--;
            else if(!(nums[l]&1)) l++;
            else{
                swap(nums[l], nums[r]);
            }
        }
        return nums;
    }
};