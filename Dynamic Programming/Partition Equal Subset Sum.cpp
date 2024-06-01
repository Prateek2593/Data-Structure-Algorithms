/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].*/

class Solution {
public:
    bool subset(vector<int>&nums, int sum){
        int t[nums.size()+1][sum+1];
        for(int i=0;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(i == 0) t[i][j] = false;
                if(j == 0) t[i][j] = true;
            }
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[nums.size()][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        
        if(sum%2 != 0) return false;
        else return subset(nums, sum/2);
    }
};
