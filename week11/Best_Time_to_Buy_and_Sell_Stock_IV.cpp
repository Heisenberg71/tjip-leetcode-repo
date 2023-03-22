// T.C: O(n*k*2) Here, n = number of days, k = number of buy&sells
// M.C: O(n*k*2)

class Solution {
private:
const static int MIN = -2000006;

int maxProfit(int pos, int rem, int buyOrSell, vector<vector<vector<int>>>& dp, vector<int>& prices){
    if(pos == prices.size()){
        if(buyOrSell == 0) return 0;
        return MIN;
    }
    if(dp[pos][rem][buyOrSell] != -1) return dp[pos][rem][buyOrSell];

    int& ret = dp[pos][rem][buyOrSell];
    ret = MIN;
    if(rem){
        if(buyOrSell == 0) ret = -prices[pos] + maxProfit(pos + 1, rem, 1, dp, prices);
        else ret = prices[pos] + maxProfit(pos + 1, rem - 1, 0, dp, prices);
    }
    ret = max(ret, maxProfit(pos + 1, rem, buyOrSell, dp, prices));

    return ret;
}
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int> > > dp(n, vector<vector<int> >(k + 1, vector<int>(2, -1)));

       return maxProfit(0, k, 0, dp, prices);
    }
};
