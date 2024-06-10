/*Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".*/

class Solution {
public:
    int LCS(string& s, string& rev_s, int n, int m){
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0) t[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == rev_s[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string rev_s = string(s.rbegin(), s.rend());
        int n = s.length();
        int m = rev_s.length();
        return LCS(s, rev_s, n, m);
    }
};
