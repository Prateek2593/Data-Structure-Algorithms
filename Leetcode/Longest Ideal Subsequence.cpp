/*
2370. Longest Ideal Subsequence
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:
t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
*/

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        /* TLE
        vector<int> t(n,1);
        int result = 1;
        for(int i = 1;i<n;i++){
            for(int j = i-1;j>=0;j--){
                if(abs(s[i] - s[j]) <= k){
                    t[i] = max(t[i], t[j]+1);
                }
            }
            result = max(result, t[i]);
        }
        return result;*/

        //O(n) 
        vector<int>t(26,0);
        int result = 0;
        for(int i = 0;i<n;i++){
            int curr = s[i] - 'a';
            int left = max(0, curr-k);
            int right = min(25, curr+k);
            int longest = 0;
            for(int j = left; j<=right;j++){
                longest = max(longest, t[j]);
            }
            t[curr] = max(t[curr], longest+1);
            result = max(result, t[curr]);
        }
        return result;
    }
};
