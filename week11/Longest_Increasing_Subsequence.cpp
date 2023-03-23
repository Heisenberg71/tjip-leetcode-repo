// T.C: O(N) Here, N = # of elements in array
// M.C: O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), LIS = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            LIS = max(ans, dp[i]);
        }
        return LIS;
    }
};
