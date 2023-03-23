// T.C: O(N) Here, N = n
// M.C: O(N)

// dp[x] = y, Here minimum y square numbers needed to make the sum x

class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
        }
        return dp[n];
    }
};
