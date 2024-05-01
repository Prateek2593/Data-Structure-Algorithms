/*213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

/*Approach 1 using recursion and memo*/
class Solution {
public:
    int t[101];
    int solve(vector<int>&nums, int i, int n){
        if(i>n) return 0;
        if(t[i] != -1) return t[i];
        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        memset(t, -1, sizeof(t));
        int take_0 = solve(nums, 0, n-2);

        memset(t, -1, sizeof(t));
        int take_1 = solve(nums, 1, n-1);

        return max(take_0, take_1);

    }
};
