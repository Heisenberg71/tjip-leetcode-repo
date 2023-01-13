/// T.C: O(N)  Here, N = number of nodes in the tree
/// M.C: O(N)


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
    vector<vector<int>> BFS_traversal(TreeNode* root){
        vector<vector<int>> zigzagwOrderNodes;
        queue <TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while(!Q.empty()){
            vector <int> sameLevelNodes;
            int len = Q.size();
            for(int i = 0; i < len; i++){
                auto frontNode = Q.front(); Q.pop();
                sameLevelNodes.push_back(frontNode -> val);
                if(frontNode -> left) Q.push(frontNode -> left);
                if(frontNode -> right) Q.push(frontNode -> right);
            }
            if(level&1) reverse(sameLevelNodes.begin(), sameLevelNodes.end());
            zigzagwOrderNodes.push_back(sameLevelNodes);
            level++;
        }
        return zigzagwOrderNodes;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        return BFS_traversal(root);
    }
};
