/// TC: O(NlogN) Here, N = size of linkedlist
/// MC: O(NlogN)


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
    ListNode* marge(ListNode* left, ListNode* right)
    {
        ListNode* dummyHead = new ListNode();
        auto saveDummy = dummyHead;

        while(left && right){
            if(left -> val < right -> val){
                dummyHead -> next = new ListNode(left -> val);
                left = left -> next;
            }
            else{
                dummyHead -> next = new ListNode(right -> val);
                right = right -> next;
            }
            dummyHead = dummyHead -> next;
        }

        while(left){
            dummyHead -> next = new ListNode(left -> val);
            left = left -> next;
            dummyHead = dummyHead -> next;
        }
        while(right){
            dummyHead -> next = new ListNode(right -> val);
            right = right -> next;
            dummyHead = dummyHead -> next;
        }

        return saveDummy -> next;
    }

    ListNode* sortList(int left, int right, vector<ListNode*> lists)
    {
        if(left > right) return NULL;
        if(left == right) return lists[left];
        int mid = left + (right - left)/2;
        return marge(sortList(left, mid, lists), sortList(mid + 1, right, lists));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return sortList(0, (int)lists.size() - 1, lists);
    }
};
