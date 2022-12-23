// TC: O(size_of_string)
// MC: O(1)

class Solution {
public:
    unordered_map <char, int> symbol_value;
    int romanToInt(string s) {
        symbol_value[ 'I' ] = 1;
        symbol_value[ 'V' ] = 5;
        symbol_value[ 'X' ] = 10;
        symbol_value[ 'L' ] = 50;
        symbol_value[ 'C' ] = 100;
        symbol_value[ 'D' ] = 500;
        symbol_value[ 'M' ] = 1000;

        int intValue = 0, suffixMax = symbol_value[ s.back() ];
        for(int i = s.size() - 1; i >= 0; i--){
            int curr_value = symbol_value[ s[i] ];
            if(suffixMax <= curr_value) intValue += curr_value;
            else intValue -= curr_value;
            suffixMax = max(suffixMax, curr_value);
        }
        return intValue;
    }
};
