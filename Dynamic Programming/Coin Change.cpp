/*322. Coin Change
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[n+1][amount+1];

        for(int i = 0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i == 0) t[i][j] = INT_MAX - 1;
                if(j == 0) t[i][j] = 0;

                if(i == 1){
                    if(j % coins[0] == 0){
                        t[i][j] = (j/coins[0]);
                    }else{
                        t[i][j] = INT_MAX - 1;
                    }
                }
            }
        }
        for(int i=2;i<=n;i++){
            for(int j = 1;j<=amount;j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(t[i-1][j] , t[i][j-coins[i-1]]+1);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][amount] == INT_MAX - 1 ? -1 : t[n][amount];
    }
};
