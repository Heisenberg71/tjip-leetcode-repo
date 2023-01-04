// TC: O(N) Here, N = number of nodes in the linkedList
// MC: O(N)

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
public:
    Node* connect(Node* root) {
        queue <Node*> BFS_queue;
        vector <Node*> BFS_seq;

        if(root) BFS_queue.push(root);
        while(!BFS_queue.empty()){
            auto currNode = BFS_queue.front(); BFS_queue.pop();
            BFS_seq.push_back(currNode);
            if(currNode -> left) BFS_queue.push(currNode -> left);
            if(currNode -> right) BFS_queue.push(currNode -> right);
        }

        for(int idx = 1; idx < BFS_seq.size(); idx++){
            if(__builtin_popcount(idx + 1) != 1) BFS_seq[idx - 1] -> next = BFS_seq[idx];
        }

        return root;
    }
};
