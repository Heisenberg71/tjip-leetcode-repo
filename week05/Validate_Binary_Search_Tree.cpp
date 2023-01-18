// TC: O(N) Here, N = number of nodes in the tree
// MC: O(D) Here, D = depth of the recursion

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
    bool isValidBST(TreeNode* root, long long L = LLONG_MIN, long long R = LLONG_MAX) {
        if(root == NULL) return true;
        if(L > root -> val || root -> val > R) return false;

        long long updatedLeftLimit = (long long)root -> val + 1;
        long long updatedRightLimit = (long long)root -> val - 1;
        bool leftSubtree = isValidBST(root -> left, L, updatedRightLimit);
        bool righSubtree = isValidBST(root -> right, updatedLeftLimit, R);

        return (leftSubtree && righSubtree);
    }
};
