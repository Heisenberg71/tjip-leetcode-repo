/// TC: O(N) Here, N = max size of both linked list
/// MC: O(N)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummyHead = new ListNode();
        auto copyDummy = dummyHead;

        int carry = 0;
        while(l1 && l2){
            int sum =  carry + l1 -> val + l2 -> val;
            int currDigit = sum %10;
            carry = sum/10;
            auto nextNode = new ListNode(currDigit, NULL);
            dummyHead -> next = nextNode;
            dummyHead = dummyHead -> next;
            l1 = l1 -> next; l2 = l2 -> next;
        }

        while(l1){
            int sum = carry + l1 -> val;
            int currDigit = sum %10;
            carry = sum/10;
            auto nextNode = new ListNode(currDigit, NULL);
            dummyHead -> next = nextNode;
            dummyHead = dummyHead -> next;
            l1 = l1 -> next;
        }

        while(l2){
            int sum = carry + l2 -> val;
            int currDigit = sum %10;
            carry = sum/10;
            auto nextNode = new ListNode(currDigit, NULL);
            dummyHead -> next = nextNode;
            dummyHead = dummyHead -> next;
            l2 = l2 -> next;
        }

        if(carry){
            auto nextNode = new ListNode(carry, NULL);
            dummyHead -> next = nextNode;
        }

        return copyDummy -> next;
    }
};
