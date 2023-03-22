// T.C: O(2^N * N) Here, N = nums.size()
// M.C: O(2^N * N)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        int numsSize = nums.size();
        for(int i = 0; i < (1 << numsSize); i++){
            vector <int> currSubset;
            for(int j = 0; j < numsSize; j++){
                if((i&(1 << j))) currSubset.push_back(nums[j]);
            }
            allSubsets.push_back(currSubset);
        }
        return allSubsets;
    }
};
