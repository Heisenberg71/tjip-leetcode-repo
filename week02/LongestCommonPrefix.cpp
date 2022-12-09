// O(total number of all characters)
// O(Max string length)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxLength = 0, maxLenStr;
        for(int i = 0; i < strs.size(); i++){
            if(maxLength < strs[i].size()){
                maxLength = strs[i].size();
                maxLenStr = i;
            }
        }

        int lcp_length = maxLength;
        for(int i = 0; i < strs.size(); i++){
            int commonPrefix = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == strs[maxLenStr][j]) commonPrefix++;
                else break;
            }
            lcp_length = min(lcp_length, commonPrefix);
        }
        
        string ans;
        for(int i = 0; i < lcp_length; i++)
            ans += strs[maxLenStr][i];
        return ans;
    }
};
