// TC: O(N)
// MC: O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffixMult[nums.size() + 5];
        suffixMult[ nums.size() ] = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
            suffixMult[i] = suffixMult[i + 1]*nums[i];
        vector <int> result;
        int prefixMult = 1;
        for(int i = 0; i < nums.size(); i++){
            result.push_back(prefixMult*suffixMult[i + 1]);
            prefixMult *= nums[i];
        }
        return result;
    }
};
