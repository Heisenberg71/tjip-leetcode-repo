class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int siz = nums.size(), placed = 0;
        for(int i = siz - 1; i >= 0; i--){
            if(nums[i] == 0){
                for(int j = i + 1; j < siz - placed; j++)
                    swap(nums[j - 1], nums[j]);
                placed++;
            }
        }
    }
};
