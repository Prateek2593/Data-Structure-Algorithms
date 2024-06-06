/*1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.*/

Solution 1: Using Recursion
class Solution {
public:
    int LCS(string &text1, string &text2, int n, int m){
        if(n == 0 || m == 0){
            return 0;
        }
        if(text1[n-1] == text2[m-1]){
            return 1+ LCS(text1, text2, n-1, m-1);
        }
        else{
            return max(LCS(text1, text2, n-1, m), LCS(text1, text2, n, m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        return LCS(text1, text2, n, m);
    }
};

Solution 2: Recursion + Memoization
class Solution {
public:
    int t[1001][1001];
    int LCS(string &text1, string &text2, int n, int m){
        if(n == 0 || m == 0){
            return 0;
        }
        if(t[n][m] != -1){
            return t[n][m];
        }
        if(text1[n-1] == text2[m-1]){
            return t[n][m] = 1+ LCS(text1, text2, n-1, m-1);
        }
        else{
            return t[n][m] = max(LCS(text1, text2, n-1, m), LCS(text1, text2, n, m-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        memset(t, -1, sizeof(t));
        return LCS(text1, text2, n, m);
    }
};

Solution 3: Using Bottom up approach(Tabulation method)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0) t[i][j] = 0;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] =  1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};
