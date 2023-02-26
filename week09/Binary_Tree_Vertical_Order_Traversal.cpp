 // T.C: O(NlogN) Here, N = number of nodes
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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        map <int, vector<pair<int, int>> > verticalOrder_nodeList;
        queue < pair<TreeNode*, int> > currNode_verticalLevel;
        
        currNode_verticalLevel.push({root, 0});
        while(!currNode_verticalLevel.empty()){
            auto u = currNode_verticalLevel.front(); currNode_verticalLevel.pop();
            verticalOrder_nodeList[u.second].push_back({u.second, u.first -> val});
            if(u.first -> left) currNode_verticalLevel.push({u.first -> left, u.second - 1});
            if(u.first -> right) currNode_verticalLevel.push({u.first -> right, u.second + 1});
        }

        vector <vector<int> > vertical_order;
        for(auto nodeList: verticalOrder_nodeList){
            vector <int> sameLevel;
            for(auto u: nodeList.second)
                sameLevel.push_back(u.second);
            vertical_order.push_back(sameLevel);
        }
        return vertical_order;
    }
};
