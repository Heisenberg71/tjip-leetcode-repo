// T.C: O(N) Here, N = number of days
// M.C: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxFromRight = 0, n = prices.size(), ans = 0;
        for(int i = n - 1; i >= 0; i--){
            maxFromRight = max(maxFromRight, prices[i]);
            ans = max(ans, maxFromRight - prices[i]);
        }
        return ans;
    }
};
