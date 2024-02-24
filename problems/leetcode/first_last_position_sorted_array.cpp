// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size() - 1;
        int left = 1, right = 0;
        int templeft = 0, tempmid = len / 2, tempright = len;
        while(templeft <= tempright){
            if(nums[tempmid] < target){
                templeft = tempmid + 1;
                tempmid = (templeft + tempright)/2;
            }
            else{
                if(nums[tempmid] == target) left = tempmid;
                tempright = tempmid - 1;
                tempmid = (templeft + tempright)/2;
            }
        }
        templeft = 0, tempmid = len / 2, tempright = len;
        while(templeft <= tempright){
            if(nums[tempmid] > target){
                tempright = tempmid - 1;
                tempmid = (templeft + tempright)/2;
            }
            else{
                if(nums[tempmid] == target) right = tempmid;
                templeft = tempmid + 1;
                tempmid = (templeft + tempright)/2;
            }
        }
        if(left > right) return {-1, -1};
        return {left, right}; 
    }
};