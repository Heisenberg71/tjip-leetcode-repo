// T.C: O(Catalan(n))) Here, Catalan(n) = NCR(2n, n)/(n + 1)
// M.C: O(Catalan(n)*n)

class Solution {
private:
    void generate(int open, int close, int n, string& seq, vector <string>& parentheses){
        if(open + close == n + n){
            parentheses.push_back(seq);
            return;
        }
        if(open < n){
            seq.push_back('(');
            generate(open + 1, close, n, seq, parentheses);
            seq.pop_back();
        }
        if(close < open){
            seq.push_back(')');
            generate(open, close + 1, n, seq, parentheses);
            seq.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector <string> parentheses;
        string seq = "";
        generate(0, 0, n, seq, parentheses);
        return parentheses;
    }
};
