// T.C: O(N) Here, N = number of elements
// M.C: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currPrefSum = 0, minPrefSum = 0, maxSumSubarraySize = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            currPrefSum += nums[i];
            maxSumSubarraySize = max(maxSumSubarraySize, currPrefSum - minPrefSum);
            minPrefSum = min(minPrefSum, currPrefSum);
        }
        return maxSumSubarraySize;
    }
};
