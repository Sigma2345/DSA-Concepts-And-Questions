// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    // get total length of linked list
    int length(ListNode*head){
        if(!head) return 0 ;
        return 1+length(head->next) ;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*prev = NULL ; 
        // if sz is 0 or 1 , only 0 or 1 node can be removed
        // so always return NULL
        if(!head || !head->next){
            return NULL ;
        } 
        ListNode*temp = head ; 
        int l = length(head) ;
        // if first node needs to be removed then just push head forward
        if(l==n){
            head = head->next ; 
            return head ;
        }
        // go to nth node from end
        for(int i = 0 ; i<l-n ; i++){
            prev = temp ; 
            temp = temp->next; 
        }
        // prev node points to the prev node to  the nth node from end
        // then make the next pointer of prev to point to next of temp
        prev->next = temp->next ; 
        return head ;
    }
};
