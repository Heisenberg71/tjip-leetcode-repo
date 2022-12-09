class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int frequency[256];
        for(int i = 0; i < 256; i++)
            frequency[i] = 0;
        
        int longestSubstringLength = 0;
        for(int L = 0, R = 0; R < s.size(); R++){
            frequency[ s[R]  ]++;
            while(frequency[ s[R] ] > 1){
                frequency[ s[L] ]--;
                L++;
            }
            longestSubstringLength = max(longestSubstringLength, R - L + 1);
        }

        return longestSubstringLength;
    }
};
