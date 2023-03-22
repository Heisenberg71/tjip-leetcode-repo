// T.C: O(number_of_houses)
// M.C: O(1)

// maxMoney[x] = y, Here, maximum y amount is gainable by robbing house from 0 to x

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector <int> maxMoney(3, 0);
        maxMoney[0] = nums[0];
        for(int i = 1; i < n; i++){
            int maxFromBack = (i >= 2) ? maxMoney[ (i - 2)%3 ] : 0; 
            maxMoney[ i%3 ] = max(maxMoney[ (i - 1)%3 ], nums[i] + maxFromBack);
        }
        return maxMoney[ (n - 1)%3 ];
    }
};
