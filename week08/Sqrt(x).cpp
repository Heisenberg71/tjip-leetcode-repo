// T.C: O(log2(x)) Here, x = value of x
// M.C: O(1)

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        
        int lo = 1, hi = x, squareRoot;
        while(lo <= hi){
            int md = lo + (hi - lo)/2;
            if(md <= x/md){
                squareRoot = md;
                lo = md + 1;
            }
            else hi = md - 1;
        }
        return squareRoot;
    }
};
