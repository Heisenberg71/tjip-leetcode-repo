// T.C: O(MULT) Here, MULT = multiplication of number of characters of all digits
// M.C: O(MULT)

class Solution {
private:
    void backtrack(int pos, string digits, string currStr, unordered_map<char, string>& digit_char, vector<string>& letterCombo){
        if(pos == digits.size()){
            letterCombo.push_back(currStr);
            return;
        }
        for(auto& ch: digit_char[ digits[pos] ]){
            currStr.push_back(ch);
            backtrack(pos + 1, digits, currStr, digit_char, letterCombo);
            currStr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> digit_char;
        char currChar = 'a';
        for(int digit = '2'; digit <= '9'; digit++){
            int limit = 3 + (digit == '7' || digit == '9');
            for(int i = 0; i < limit; i++){
                digit_char[digit] += currChar;
                currChar++;
            }
        }

        vector<string> letterCombo;
        if(digits == "") return letterCombo;
        backtrack(0, digits, "", digit_char, letterCombo);
        return letterCombo;
    }
};
