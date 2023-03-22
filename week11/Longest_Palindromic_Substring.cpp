// T.C: O(N^2)
// M.C: O(N)

class Solution {
private:
bool isPalindrome(int L, int R, vector< vector<int> >& isPalindromeDP, string& s){
    if(L > R) return true;
    return isPalindromeDP[L][R] = (s[L] == s[R] && isPalindrome(L + 1, R - 1, isPalindromeDP, s));
}

public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector< vector<int> > isPalindromeDP;
        isPalindromeDP.resize(len + 1, vector<int>(len + 1, -1));
        
        for(int currLen = len; currLen > 0; currLen--){
            for(int L = 0, R = currLen - 1; R < len; L++, R++){
                if(isPalindrome(L, R, isPalindromeDP, s)){
                    return s.substr(L, R - L + 1);
                }
            }
        }

        return "";
    }
};
