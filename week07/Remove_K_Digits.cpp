// T.C: O(N), Here, N = num string size
// M.C: O(N)
class Solution {
public:
    string removeKdigits(string num, int k) {
        string smallestNum;
        for(int i = 0; i < num.size(); i++){
            while(k && !smallestNum.empty() && num[i] < smallestNum.back()){
                smallestNum.pop_back();
                k--;
            }
            if((smallestNum.empty() && num[i] != '0') || !smallestNum.empty()) smallestNum.push_back(num[i]);
        }
        while(k && !smallestNum.empty()){
            smallestNum.pop_back();
            k--;
        }
        if(smallestNum.empty()) smallestNum.push_back('0');
        return smallestNum;
    }
};
