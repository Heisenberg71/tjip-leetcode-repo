// O(total number of all characters)
// O(Max string length)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxLength = 0, maxLengthIndex;
        for(int i = 0; i < strs.size(); i++){
            if(maxLength < strs[i].size()){
                maxLength = strs[i].size();
                maxLengthIndex = i;
            }
        }

        int longesetCommonPrefix_length = maxLength;
        for(int i = 0; i < strs.size(); i++){
            int commonPrefix = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == strs[maxLengthIndex][j]) commonPrefix++;
                else break;
            }
            longesetCommonPrefix_length = min(longesetCommonPrefix_length, commonPrefix);
        }
        
        string ans;
        for(int i = 0; i < longesetCommonPrefix_length; i++)
            ans += strs[maxLengthIndex][i];
        return ans;
    }
};
