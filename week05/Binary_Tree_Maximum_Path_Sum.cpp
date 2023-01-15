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
    int DFS_traversal(TreeNode* currNode, int &maxPathSum){
        if(currNode == NULL) return 0;
        int maxPathSumFromLeftNode =  DFS_traversal(currNode -> left, maxPathSum);
        int maxPathSumFromRightNode = DFS_traversal(currNode -> right, maxPathSum);
        maxPathSum = max(maxPathSum, maxPathSumFromLeftNode + currNode -> val + maxPathSumFromRightNode);
        return max(0, currNode -> val + max(maxPathSumFromLeftNode, maxPathSumFromRightNode));
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        DFS_traversal(root, maxPathSum);
        return maxPathSum;
    }
};
