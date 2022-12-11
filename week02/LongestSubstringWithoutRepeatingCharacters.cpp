// O(N)
// O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector <int> frequency(256, 0); // For all ASCII characters
        
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
