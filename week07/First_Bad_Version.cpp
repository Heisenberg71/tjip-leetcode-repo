// T.C: O(logN) Here, N = total number of prducts
// M.C: O(1)


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
    const static int INVALID = -1;
private:
    int binarySearch(int lo, int hi)
    {
        int updatedBad = INVALID;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isBadVersion(mid)){
                updatedBad = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return updatedBad;
    }
public:
    int firstBadVersion(int n) {
        return binarySearch(1, n);
    }
};
