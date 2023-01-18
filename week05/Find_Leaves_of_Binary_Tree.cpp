// T.C: O(N) Here, N = number of nodes in the tree
// M.C: O(N)

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
    int findHeight(TreeNode* currNode, vector< vector<int> >& leaves)
    {
        if(currNode == NULL) return 0;

        int currNodeDepth = 1 + max(findHeight(currNode -> left, leaves), findHeight(currNode -> right, leaves));
        if(leaves.size() < currNodeDepth) leaves.push_back({});
        leaves[currNodeDepth - 1].push_back(currNode -> val);

        return currNodeDepth;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector< vector<int> > leaves;
        findHeight(root, leaves);
        return leaves;
    }
};
