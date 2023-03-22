// T.C: O(size of string)
// M.C: O(1)

class Solution {
public:
    int numDecodings(string s){
        int siz = s.size() + 1;
        vector<int> ways(3, 0);
        s = '$' + s;
        ways[0] =  1;
        ways[1] = (s[1] != '0');
        for(int i = 2; i < siz; i++){
            int currWays = 0;
            if(s[i] != '0') currWays += ways[ (i - 1)%3 ];
            if(s[i - 1] != '0' && stoi(s.substr(i - 1, 2)) <= 26) currWays += ways[ (i - 2)%3 ];
            ways[ i%3 ] = currWays;
        }
        return ways[ (siz - 1)%3 ];
    }
};
