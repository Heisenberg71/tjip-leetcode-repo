// T.C: O(N) Here, N = the value of n
// M.C: O(N)

class Solution {
public:
    int countPrimes(int n) {
        vector <bool> primeStatus(n + 1, 1);
        for(int i = 2; i*i < n; i++){
            if(!primeStatus[i]) continue;
            for(int j = i*i; j < n; j += i)
                primeStatus[j] = 0;
        }

       int primeCounter = 0;
       for(int i = 2;  i < n; i++)
           primeCounter += primeStatus[i];

      return primeCounter;
    }
};
