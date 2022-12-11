class Solution {
public:
    string minWindow(string s, string t) {
        int freq_s[256], freq_t[256];
        for(int i = 0; i < 256; i++)
            freq_s[i] = freq_t[i] = 0;

        for(int i = 0; i < t.size(); i++)
            freq_t[ t[i] ]++;

        freq_s[ s[0] ] = 1;
        int minWindow = s.size() + 1, startWindow = -1;
        for(int L = 0, R = 0; R < s.size(); ){
            bool valid = 1;
            for(int j = 0; j < 256; j++){
                if(freq_s[j] < freq_t[j]) valid = 0;
            }
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