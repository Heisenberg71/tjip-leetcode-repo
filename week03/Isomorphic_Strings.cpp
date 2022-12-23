// TC: O(N) N = max_size_of_string
// MC: O(1)

class Solution {
public:
    static const int MAX_CHAR_LIM = 256;

    bool isIsomorphic(string s, string t) {
        vector <int> replaceMap_S(MAX_CHAR_LIM, 0), replaceMap_T(MAX_CHAR_LIM, 0);
        for(int i = 0; i < s.size(); i++){
            replaceMap_S[ s[i] ] = t[i];
            replaceMap_T[ t[i] ] = s[i];
        }
        
        for(int i = 0; i < s.size(); i++){
            if(replaceMap_S[ s[i] ] != t[i] || replaceMap_T[ t[i] ] != s[i]) return false;
        }
        return true;
    }
};
