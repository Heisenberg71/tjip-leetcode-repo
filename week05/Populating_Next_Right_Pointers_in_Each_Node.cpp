// T.C: O(N) /// Here, N = number of nodes
// M.C: O(L) /// Here, L max of sum of nodes in 2 consecutive levels

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void BFS_traverse(Node* root){
        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto frontNode = q.front(); q.pop();
                if(i + 1 < len) frontNode -> next = q.front();
                if(frontNode -> left) q.push(frontNode -> left);
                if(frontNode -> right) q.push(frontNode -> right);
            }
        }
    }

public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        BFS_traverse(root);
        return root;
    }
};
