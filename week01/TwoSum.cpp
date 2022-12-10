class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> mp;
        vector <int> ans;
        mp[ nums[0] ] = 1;
        for(int i = 1; i < nums.size(); i++){
            if(mp[ target - nums[i] ]){
                ans.push_back(i);
                ans.push_back(mp[ target - nums[i] ] - 1);
                return ans;
            }
            mp[ nums[i] ] = i + 1;
        }
        return ans;
    }
};
