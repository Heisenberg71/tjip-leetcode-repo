class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int siz = prices.size();
        int prefixMin[siz + 5], suffixMax[siz + 5];

        int maxSuffix = 0, minPrefix = 10004;
        for(int i = 0; i < siz; i++){
            minPrefix = min(minPrefix, prices[i]);
            prefixMin[i] = minPrefix;
        } 

        for(int i = siz - 1; i >= 0; i--){
            maxSuffix = max(maxSuffix, prices[i]);
            suffixMax[i] = maxSuffix;
        }

        int ans = 0;
        for(int i = 0; i < siz; i++)
            ans = max(ans, suffixMax[i] - prefixMin[i]);
        return ans;
    }
};
