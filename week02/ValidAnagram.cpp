class Solution {
public:
    static const MAX_CHAR_SIZE = 26;
    
    bool isAnagram(string s, string t) {
        vector <int> freq_s(MAX_CHAR_SIZE, 0);

        for(int i = 0; i < s.size(); i++)
            freq_s[ s[i] - 'a' ]++;

        for(int i = 0; i < t.size(); i++)
            freq_s[ t[i] - 'a' ]--;

        bool valid = 1;
        for(int i = 0; i < 26; i++){
            if(freq_s[i] != 0) valid = 0;
        }

        return valid;
    }
};
