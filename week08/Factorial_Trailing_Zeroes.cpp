// T.C: O(log5(N)) Here, N = n
// M.C: O(1)

class Solution {
public:
    int trailingZeroes(int n) {
        int tralling_zeroes = 0;
        for(int div = 5; div <= n; div *= 5)
            tralling_zeroes += n/div;
        return tralling_zeroes;
    }
};
