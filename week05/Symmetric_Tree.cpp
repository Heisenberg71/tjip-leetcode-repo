// T.C: O(N) Here, N = number of nodes in the tree
// M.C: O(D) Here, D = max depth of recursion


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
private:
    bool isSymetricSubtree(TreeNode* u, TreeNode* v){
        if(u == NULL && v == NULL) return true;
        if(u == NULL || v == NULL || u -> val != v -> val) return false;
        return (isSymetricSubtree(u -> left, v -> right) && isSymetricSubtree(u -> right, v -> left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymetricSubtree(root -> left, root -> right);
    }
};
