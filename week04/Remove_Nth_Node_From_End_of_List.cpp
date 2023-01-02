/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        auto nextNode = node -> next;
        *node = *(node -> next);
        delete(nextNode);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto frontPtr = head;
        auto backPtr = head;
        ListNode* prevNode = NULL;
        while(n--)
            frontPtr = frontPtr -> next;

        while(frontPtr){
            frontPtr = frontPtr -> next;
            prevNode = backPtr;
            backPtr = backPtr -> next;
        }

        if(backPtr -> next) deleteNode(backPtr);
        else if(prevNode) prevNode -> next = NULL;
        else return NULL;

        return head;
    }
};
