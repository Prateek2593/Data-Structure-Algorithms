/*260. Single Number III
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.*/
Solution 1:
class Solution {
public:
    //O(n+n) time and O(n) space complexity
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int &num : nums){
            mp[num]++;
        }
        vector<int>result;
        for(auto &it : mp){
            if(it.second == 1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};

Solution 2:
class Solution {
public:
    //O(n) time and O(1) space complexity
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        
        for(int &num :  nums) xorr ^= num;
        
        long long mask = (xorr) & (-xorr);
        
        int groupA = 0;
        int groupB = 0;
        
        for(int &num : nums){
            if(mask & num) groupA ^= num;
            else groupB ^= num;
        }
        
        return {groupA, groupB};
    }
};
