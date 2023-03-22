// T.C: O(amount*total_coins)
// M.C: O(amount)

// coinCount[x] = y; Here, minimum y coins needed to make amount x

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector <int> coinCount(amount + 1, amount + 1);
        coinCount[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i < coins[j]) continue;
                coinCount[i] = min(coinCount[i], 1 + coinCount[i - coins[j]]);
            }
        }
        return (coinCount[amount] == amount + 1) ? -1 : coinCount[amount]; 
    }
};
