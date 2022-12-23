// TC: O(n^2), N = number_of_nodes
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
    vector <TreeNode*> dupSubTrees;
    unordered_map <string, int> subTreeFreq;

    string DFS(TreeNode* root){
        if(root == NULL) return "*";
        string leftSubSeq = DFS(root -> left);
        string rightSubSeq = DFS(root -> right);
        string currSeq = to_string(root -> val) + ',' + leftSubSeq + ',' + rightSubSeq;

        if(subTreeFreq.count(currSeq) && subTreeFreq[currSeq] == 1) dupSubTrees.push_back(root);
        subTreeFreq[currSeq]++;
        return currSeq;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dupSubTrees.clear();
        subTreeFreq.clear();
        DFS(root);
        return dupSubTrees;
    }
};
