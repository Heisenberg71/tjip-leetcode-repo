// TC: O(N^2 * logN) Here, N = size of linkedlist
// MC: O(NlogN)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* randomLinker(Node* currNode, Node* currCopyNode, int position)
    {
        while(position){
            currNode = currNode -> next;
            currCopyNode = currCopyNode -> next;
            position--;
        }
        return currCopyNode;
    }

    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        map <Node*,  int> node_place;
        
        auto currNode = head;
        auto copyHead = new Node(head -> val);
        auto currCopyNode = copyHead;
        int serialNo = 0;
        while(currNode){
            node_place[currNode] = serialNo++;
            if(currNode -> next){
                auto nextNode = currNode -> next;
                auto copyNode = new Node(nextNode -> val);
                currCopyNode -> next = copyNode;
            }
            
            currNode = currNode -> next;
            currCopyNode = currCopyNode -> next;
        }

        currNode = head;
        currCopyNode = copyHead;
        while(currNode){
            if(currNode -> random){
                cout << currNode -> random << endl;
                currCopyNode -> random = randomLinker(head, copyHead, node_place[ currNode -> random ]);
            }

            currNode = currNode -> next;
            currCopyNode = currCopyNode -> next;
        }

        return copyHead;
    }
};
