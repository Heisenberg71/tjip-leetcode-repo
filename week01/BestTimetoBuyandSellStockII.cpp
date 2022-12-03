//O(N) Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size() + 5];
        if(prices.size() == 1) return 0;

        dp[0] = 0;
        dp[1] = max(0, prices[1] - prices[0]);
        int prevMax = dp[0] - prices[1];
        for(int i = 2; i < prices.size(); i++){
            dp[i] = dp[i - 1];
            dp[i] = max(dp[i], max(prices[i] + prevMax, prices[i] - prices[0]));
            prevMax = max(prevMax, dp[i - 1] - prices[i]);
        }
        return dp[ prices.size() - 1 ];
    }
};

//----------------------------------------------------------------------------------------------------------------

//O(N^2) Solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[prices.size() + 5];
        dp[0] = 0;
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            dp[i] = dp[i - 1];
            for(int j = 0; j < i; j++){
                if(j) dp[i] = max(dp[i], dp[j - 1] + prices[i] - prices[j]);
                else dp[i] = max(dp[i], prices[i] - prices[j]);
            }
        }
        return dp[ prices.size() - 1 ];
    }
};
