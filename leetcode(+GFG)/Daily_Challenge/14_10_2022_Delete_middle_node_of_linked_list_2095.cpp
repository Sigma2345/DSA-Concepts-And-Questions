// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL ; 
        ListNode*fast = head , *slow = head , *prev =  head ;
        int i = 0 ; 
        // this approach leads to slow ptr pointing to middle node 
        while(fast && fast->next) {
            if(i>0) prev = prev->next ; // this is done so that prev points just behind slow
            fast = fast->next->next ; 
            slow = slow->next ; 
            i++ ; 
        }
        prev->next = slow->next ; // connect prev node and next of slow node
        return head ;
    }
};
