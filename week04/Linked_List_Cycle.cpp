/// TC: O(N)
/// MC: O(1)
  
  **
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        auto slowPointer = head;
        auto fastPointer = head;
        while(fastPointer -> next && fastPointer -> next -> next){
            slowPointer = slowPointer -> next;
            fastPointer = fastPointer -> next -> next;
            if(slowPointer == fastPointer) return true;
        }
        return false;
    }
};
