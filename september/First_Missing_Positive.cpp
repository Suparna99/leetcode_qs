/*
 First Missing Positive

Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3

Example 2:

Input: [3,4,-1,1]
Output: 2

Example 3:

Input: [7,8,9,11,12]
Output: 1

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int base = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                nums[base++] = nums[i];
            }
        }
        nums.resize(base);
        n = base;
        sort(nums.begin(),nums.end());
        base = 1;
        for(int i=0;i<n;i++){
            if( nums[i] > base){
                return base;
            }
            base = nums[i] + 1;
        }
        return base;
    }
};
