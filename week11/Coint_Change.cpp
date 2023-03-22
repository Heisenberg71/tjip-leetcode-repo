// T.C: O(amount*total_coins)
// M.C: O(amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i < coins[j]) continue;
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount]; 
    }
};
