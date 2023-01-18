// TC: O(N) Here, N = number of nodes in the tree
// MC: O(D) Here, D = depth of the recursion

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        auto leftResult = findLCA(root -> left, p, q);
        auto rightResult = findLCA(root -> right, p, q);
        if(leftResult && rightResult) return root;
        return leftResult ? leftResult : rightResult;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};
