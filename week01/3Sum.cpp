// TC: O(N^2)
// MC: O(N^2)
// Here, N = updated size of nums.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map <int, int> freq;
        unordered_map <long long, bool> stored;
        vector < vector <int> > result;
        vector <int> nums2;
        for(int i = 0; i < nums.size(); i++){
            if(freq[ nums[i] ] < 3){
                 nums2.push_back(nums[i]);
                 freq[ nums[i] ]++;
            }
        }
        nums = nums2;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int val1 = nums[i], val2 = nums[j];
                int val3 = -(val1 + val2);
                if(freq.count(val3)){
                    vector <int> temp;
                    temp.push_back(val1);
                    temp.push_back(val2);
                    temp.push_back(val3);
                    sort(temp.begin(), temp.end());
                    freq[ val1 ]--, freq[ val2 ]--, freq[ val3 ]--;
                    if(freq[ val1 ] >= 0 && freq[ val2 ] >= 0 && freq[ val3 ] >= 0){
                        long long hash = ((temp[0]*300005LL) + temp[1])*300005LL + temp[2];
                        if(!stored.count(hash)){
                            result.push_back(temp);
                            stored[hash] = 1;
                        }
                    }
                    freq[val1]++, freq[val2]++, freq[val3]++;
                }
            }
        }

        return result;
    }
};
