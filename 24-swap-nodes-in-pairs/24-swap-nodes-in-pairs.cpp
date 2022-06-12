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
    ListNode* swapPairs(ListNode* head) {
        
        // 1->2->3->4
        // t = 3
        // 
        if(!head || !head->next) return head;
        
        ListNode* temp = head->next->next;
        ListNode* t2 = head;
        
        head = head->next;
        t2->next = t2->next->next;
        head->next = t2;
        head->next->next = swapPairs(head->next->next);;
        return head;
    }
};