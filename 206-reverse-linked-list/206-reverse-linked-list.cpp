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
    
//     1. RECURSIVE
//     ListNode* reverseList(ListNode* head) {
        
//         if(!head || !head->next) return head;
        
//         ListNode*rev_head = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return rev_head;
//     }
    
    // 2. ITERATIVE

        ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode*prev  = NULL, *nxt  = NULL;
            
        ListNode* curr = head;
        
            while(curr != NULL) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;

            }
            return prev;
    }
};