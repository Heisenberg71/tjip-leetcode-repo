// T.C: O(N) Here, N = number of nodes
// M.C : O(D) D = max depth of recursion stack memory

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
    int traverse(TreeNode* currNode, int &max_path_sum){
        if(currNode == NULL) return 0;
        int left_node = traverse(currNode -> left, max_path_sum);
        int right_node = traverse(currNode -> right, max_path_sum);
        int max_subtree = max(0, max(left_node, right_node));
        max_path_sum = max(max_path_sum, currNode -> val + max(max_subtree, left_node + right_node));
        return currNode -> val + max_subtree;
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int max_path_sum = root -> val;
        traverse(root, max_path_sum);
        return max_path_sum;
    }
};
