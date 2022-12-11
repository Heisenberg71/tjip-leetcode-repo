// TC: O(string_size)
// MC: O(string_size)

class Solution {
public:
    bool isValid(string s) {

        stack <char> opennings;
        bool valid = 1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                opennings.push(s[i]);
            else{
                if(!opennings.empty()){
                    bool found = 0;
                    if(opennings.top() == '(' && s[i] == ')') found = 1;
                    if(opennings.top() == '{' && s[i] == '}') found = 1;
                    if(opennings.top() == '[' && s[i] == ']') found = 1;
                    
                    if(found) opennings.pop();
                    else valid = 0;
                }
                else valid = 0;
            }
        }

        return (valid && opennings.empty());
    }
};
