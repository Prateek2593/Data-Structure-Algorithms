/*Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
Example 1:
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int t[n+1][m+1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if(i == 0 || j == 0) t[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string result;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result.push_back(str1[i - 1]);
                i--;
                j--;
            } else {
                if (t[i - 1][j] > t[i][j - 1]) {
                    result.push_back(str1[i - 1]);
                    i--;
                } else {
                    result.push_back(str2[j - 1]);
                    j--;
                }
            }
        }
        while (i > 0) {
            result.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0) {
            result.push_back(str2[j - 1]);
            j--;
        }
        reverse(begin(result), end(result));
        return result;
    }
};
