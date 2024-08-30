/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getLoopNode(ListNode *head) {
        ListNode*slow = head;
        ListNode*fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return slow;
        }
        return NULL;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = getLoopNode(head);
        if(fast == NULL) return NULL;

        ListNode* slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};