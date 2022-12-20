// TC: O(N)
// MC: O(1)

class Solution {
public:
    string minWindow(string s, string t) {
        
        vector <int> freq_s(256, 0), freq_t(256, 0);

        for(int i = 0; i < t.size(); i++)
            freq_t[ t[i] ]++;
        
        freq_s[ s[0] ] = 1;
        int minWindow = s.size() + 1, startWindow = -1;
        for(int L = 0, R = 0; R < s.size(); ){
            bool valid = 1;
            if(freq_s[ s[R] ] < freq_t[ t[R] ]) valid = 0;
            if(valid){
                freq_s[ s[L] ]--;
                if(R - L + 1 < minWindow){
                    minWindow = R - L + 1;
                    startWindow = L;
                }
                L++;
            }
            else{
                 R++;
                 if(R < s.size()) freq_s[ s[R] ]++;
                 
            }
        }
        string windowStr = "";
        if(startWindow == -1) return windowStr;
        for(int i = startWindow; i < startWindow + minWindow; i++){
            windowStr += s[i];
        }
        return windowStr;
    }
};
