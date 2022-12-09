// TC: O(NlogN)
// MC: O(total number of characters)

class Solution {
public:
    static bool compare(pair<string, string> &a, pair<string, string> &b)
    {
        return a.first < b.first;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector < pair<string, string> > sorted_original;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            sorted_original.push_back({temp, strs[i]});
        }
        sort(sorted_original.begin(), sorted_original.end(), compare);
        
        vector <vector <string> > groupAnagrams;
        groupAnagrams.push_back({sorted_original[0].second});
        for(int i = 1; i < sorted_original.size(); i++){
            if(sorted_original[i - 1].first == sorted_original[i].first){
                groupAnagrams.back().push_back(sorted_original[i].second);
            }
            else{
                groupAnagrams.push_back({sorted_original[i].second});
            }
        }

        return groupAnagrams;
    }
};
