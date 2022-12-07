//TC: O(N)
//MC: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, winner = -1;
        for(int i = 0; i < nums.size(); i++){
            if(vote == 0){
                winner = nums[i];
                vote = 1;
            }
            else if(winner == nums[i]) vote++;
            else vote--;
        }
        int winner_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(winner == nums[i]) winner_count++;
        }

        if(2*winner_count > nums.size()) return winner;
        return -1;
    }
};

