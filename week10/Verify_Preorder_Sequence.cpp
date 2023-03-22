// T.C: O(N) Here, N = size of preorder vector
// M.C: O(D) Here, D = depth of recursion stack memory

class Solution {
private:
    void verify(int& currIdx, vector<int>& preorder, int L, int R){
        if(currIdx == preorder.size()) return;
        int mid = preorder[currIdx];
        if(mid < L || mid > R) return;
        currIdx++;
        verify(currIdx, preorder, L, mid - 1);
        verify(currIdx, preorder, mid + 1, R);
    }
public:
    bool verifyPreorder(vector<int>& preorder) {
        int currIdx = 0;
        verify(currIdx, preorder, INT_MIN, INT_MAX);
        return (currIdx == preorder.size()) ? true: false;
    }
};
