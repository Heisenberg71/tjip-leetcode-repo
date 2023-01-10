// TC: O(N) Here, N = size of nums vector
// MC: O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildBST(int L, int R, vector <int> &nums)
    {
        if(L > R) return NULL;
        int mid = L + (R - L)/2;
        auto currNode = new TreeNode(nums[mid]);
        currNode -> left = buildBST(L, mid - 1, nums);
        currNode -> right = buildBST(mid + 1, R, nums);
        return currNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(0, (int)nums.size() - 1, nums);
    }
};
