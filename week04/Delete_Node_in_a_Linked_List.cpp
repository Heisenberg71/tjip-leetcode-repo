// TC: O(1)
// MC: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* deleteNode) {
        auto nextNode = deleteNode -> next;
        *deleteNode = *deleteNode -> next;
        delete nextNode;
    }
};
