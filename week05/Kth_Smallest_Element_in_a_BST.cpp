// T.C: O(N) Here, N = number of nodes in the tree
// M.C: O(D) Here, D = Depth of recusion stack memory

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
    void inOrderTraversal(TreeNode* root, int &position, int &kthSmallestValue, int k){
        if(root == NULL) return;
        inOrderTraversal(root -> left, position, kthSmallestValue, k);
        if(position == k) kthSmallestValue = root -> val;
        position++;
        inOrderTraversal(root -> right, position, kthSmallestValue, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int position = 1, kthSmallestValue;
        inOrderTraversal(root, position, kthSmallestValue, k);
        return kthSmallestValue;
    }
};
