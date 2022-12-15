// TC: O(N)
// MC: O(1)


class Solution {
public:
    int maxSubstrWithFixedChar(int uniqueCharLimit, string &s, int k)
    {
        int L = 0, R = 0, max_len = 0;
        int unqCharInWindow = 0;
        int cntCharOfFreqK = 0;
        vector <int> freq(26, 0);

        while(R < s.size()){
            freq[ s[R] - 'a' ]++;
            unqCharInWindow += (freq[ s[R] - 'a' ] == 1);
            cntCharOfFreqK += (freq[ s[R] - 'a' ] == k);
            R++;

            while(uniqueCharLimit < unqCharInWindow){
                freq[ s[L] - 'a' ]--;
                unqCharInWindow -= (freq[ s[L] - 'a' ] == 0);
                cntCharOfFreqK -= (freq[ s[L] - 'a' ] == k - 1);
                L++;
            }

            if(unqCharInWindow == cntCharOfFreqK){
                max_len = max(max_len, R - L);
            }
        }

        return max_len;
    }

    int longestSubstring(string s, int k) {
        int longestSubstr = 0;
        for(int distinctChar = 1; distinctChar <= 26; distinctChar++){
            longestSubstr = max(longestSubstr, maxSubstrWithFixedChar(distinctChar, s, k));
        }
        return longestSubstr;
    }
};
