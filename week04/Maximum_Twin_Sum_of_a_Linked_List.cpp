/// TC: O(N) Here, N = size of linked list
/// MC: O(1)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = NULL;
        auto currNode = head;
        while(currNode != NULL){
            auto nextNode = currNode -> next;
            currNode -> next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    int findLength(ListNode *head)
    {
        int len = 0;
        auto currNode = head;
        while(currNode){
             currNode = currNode -> next;
             len++;
        }
        return len;
    }

    ListNode* cut_linkedlist_in_the_middle(ListNode* head, int length)
    {
        int halfLength = length/2 - 1;
        auto currNode = head;
        while(halfLength--)
            currNode = currNode -> next;
        auto head2 = currNode -> next;
        currNode -> next = NULL;
        return head2;
    }

    void restoreLinkedlist(ListNode* head, ListNode* head2)
    {
        auto currentHead = head;
        reverseList(head);
        currentHead -> next = head2;
    }

    int pairSum(ListNode* head) {
        
        int length = findLength(head);
        auto head2 = cut_linkedlist_in_the_middle(head, length);
        head = reverseList(head);

        auto copyHead = head;
        auto copyHead2 = head2;

        int maxTwinSum = 0;
        while(head){
            maxTwinSum = max(maxTwinSum, head -> val + head2 -> val);
            head = head -> next;
            head2 = head2 -> next;
        }

        restoreLinkedlist(copyHead, copyHead2);

        return maxTwinSum;
    }
};
