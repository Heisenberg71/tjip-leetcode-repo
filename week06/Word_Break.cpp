// T.C: O(N*M) Here, N = size of s string
// M.C: O(N)   Here, M = sum of total characters in wordDictionary

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector <int> dp(s.size() + 1, false); // dp[i] = 1/0, if there exist some collection of words from dictionary using which 1 to i'th position or i'th prefix can/cannot be made
                                              // by the defination if dp[ s.size() ] is the answer
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < wordDict.size(); j++){
                bool matched = 1;
                for(int k = 0; k < wordDict[j].size(); k++){
                    if(i - 1 + k > s.size() || s[i - 1 + k] != wordDict[j][k]){
                        matched = 0;
                        break;
                    }
                }
                if(matched) dp[ i + wordDict[j].size() - 1 ] |= dp[i - 1];
            }
        }

        return dp[s.size()];
    }

};
