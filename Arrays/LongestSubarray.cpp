//Program to print the longest subarray with sum k
//only positive number taken in array
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0, right=0, maxLen = 0;
    long long sum = a[0];
    int n = a.size();
    while(right<n){
        while(left<=right && sum>k){
            sum -=a[left];
            left++;
        }

        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }

        right++;
        if(right<n){
            sum+=a[right];
        }
    }
    return maxLen;
}

//Program to print the longest subarray with sum k
//positives, negatives and zero number taken in array
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    map<long long,int>preSumMap;
    long long sum=0;
    int maxLen=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum +=nums[i];
        if(sum==k){
            maxLen=max(maxLen,i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){
            preSumMap[sum]=i;
        }
    }
    return maxLen;
}