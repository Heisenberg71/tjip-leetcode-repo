/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void serialization_DFS(TreeNode* currNode, string &serialized_string){
        serialized_string += (currNode -> left) ? to_string(currNode -> left -> val) + "," : "null,";
        serialized_string += (currNode -> right) ? to_string(currNode -> right -> val) + "," : "null,";
        
        if(currNode -> left) serialization_DFS(currNode -> left, serialized_string);
        if(currNode -> right) serialization_DFS(currNode -> right, serialized_string);
    }

    void deserialization_DFS(TreeNode* currNode, queue<string> &nodeValue){
        string Lstr = nodeValue.front(); nodeValue.pop();
        string Rstr = nodeValue.front(); nodeValue.pop();

        if(Lstr != "null"){
            TreeNode* L = new TreeNode( stoi(Lstr) );
            currNode -> left = L;
            deserialization_DFS(L, nodeValue);
        }
        if(Rstr != "null"){
            TreeNode* R = new TreeNode( stoi(Rstr) );
            currNode -> right = R;
            deserialization_DFS(R, nodeValue);
        }

    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {   /// T.C: O(N) Here, N = number of nodes in the tree
        if(root == NULL) return "";      /// M.C: O(N)

        string serialized_string = to_string(root -> val) + ",";
        serialization_DFS(root, serialized_string);
        serialized_string.pop_back();
        return serialized_string;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {  /// T.C: O(N) Here, N = string size
        if(data == "") return NULL;       /// M.C: O(N)

        stringstream ss(data);
        queue <string> nodeValue;
        string eachNode;
        while (!ss.eof()) {
            getline(ss, eachNode, ',');
            nodeValue.push(eachNode);
        }
    
        TreeNode* root = new TreeNode(stoi(nodeValue.front())); nodeValue.pop();
        deserialization_DFS(root, nodeValue);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
