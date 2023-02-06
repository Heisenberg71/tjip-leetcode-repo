// T.C: O(N) Here, N = size of nums vector
// M.C: O(1)


class Solution {
public:
    int jump(vector<int>& nums) {
        int minJumps = 0, begin = 0, end = 0;
        for(int i = 0; i < (int)nums.size() - 1; ++i) {
            end = max(end, i + nums[i]);
            if(i == begin) {
                minJumps++;
                begin = end;
            }
        }
        return minJumps;
    }
};
