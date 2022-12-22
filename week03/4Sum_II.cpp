class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map <int, int> pairwise_sum;

        for(auto a: nums1)
            for(auto b: nums2)
                pairwise_sum[ a + b ]++;

        int zero_sum_cnt = 0;
        for(auto a: nums3){
            for(auto b: nums4){
                if(pairwise_sum.count(-(a + b)))
                    zero_sum_cnt += pairwise_sum[ -(a + b) ];
            }
        }

        return zero_sum_cnt;
    }
};
