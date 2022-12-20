// TC: O(length_of_output_string)
// MC: O(length_of_output_string)

class Solution {
public:
    string decodeString(string s) {
        stack < pair<string, int> > stk;
        stk.push({"", 1});

        int copy = 0;
        for(int i = 0; i < s.size(); i++){
            if('0' <= s[i] && s[i] <= '9') copy = 10*copy + s[i] - '0';
            else if(s[i] == '['){
                stk.push({"", copy});
                copy = 0;
            }
            else if(s[i] == ']'){
                string topStr;
                while(stk.top().second--) topStr += stk.top().first;
                stk.pop();
                stk.top().first += topStr;
            }
            else{
                stk.top().first.push_back(s[i]);
            }
        }

        return stk.top().first;
    }
};
