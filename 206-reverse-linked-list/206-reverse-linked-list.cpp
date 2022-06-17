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
//     ITERATIVE
//     ListNode* reverseList(ListNode* head) {
        
//         if(!head || !head->next ) return head;
        
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* prev = NULL, *nextptr = NULL, *curr = head;
        
//         while(curr) {
//             nextptr = curr->next;
//             curr->next = prev;
            
//             prev = curr;
//             curr = nextptr;
//         }
//         return prev;
        
//     }
    
//     RECURSIVE
        ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next ) return head;
        
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
            
        return newhead;
        
    }
    
};