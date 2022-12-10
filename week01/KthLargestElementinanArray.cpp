// TC: O(N + 20000) Here, N = size of nums vector
// MC: O(M) Here, M = total possible range of values [-10000, 10000] --> 20000

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int freq[20004];
        for(int i = 0; i < 20004; i++)
            freq[i] = 0;
        for(int i = 0; i < nums.size(); i++)
            freq[ 10000 + nums[i] ]++;
        for(int i = 20000; i >= 0; i--){
            while(k && freq[i]){
                freq[i]--;
                k--;
            }
            if(!k) return i - 10000;
        }
        return -1;
    }
};
