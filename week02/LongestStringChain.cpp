// TC: O(N*N*max(Max_string_size, logN))
// MC: O(N)

class Solution {
public:
    static bool compare(string &a, string &b){
        return a.size() < b.size();
    }

    bool isPredecessor(string &before, string &after)
    {
        if(before.size() + 1 != after.size()) return 0;

        for(int i = 0; i < before.size(); i++){
            if(before[i] != after[i]){
                for(int j = i, k = i + 1; k < after.size(); j++, k++)
                    if(before[j] != after[k]) return 0;
            }
        }

        return 1;
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        vector <int> dp(words.size(), 1);
        int longestChainLength = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i])) dp[i] = max(dp[i], 1 + dp[j]);
            }
            longestChainLength = max(longestChainLength, dp[i]);
        }

        return longestChainLength;
    }
};
