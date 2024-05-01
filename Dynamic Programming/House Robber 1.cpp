/*198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.*/

/* Approach 1 using recursion and memo*/
class Solution {
public:
    int t[101];
    int solve(vector<int>&nums, int i, int n){
        if(i >= n) return 0;
        if(t[i] != -1) return t[i];

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};

/* Approach 2 using bottom up */
class Solution {
public:
int rob(vector<int>&nums){
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>t(n+1, 0);
        t[0] = 0;
        t[1] = nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(steal, skip);
        }
        return t[n];
    }
};
