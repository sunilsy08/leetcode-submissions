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
    ListNode* reverse(ListNode* head){
        if(head == NULL) return head;

        ListNode* prev, *next, *curr=head;
        prev = NULL, next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        slow->next = NULL;

        ListNode * resp = new ListNode(0);
        ListNode * resphead = resp;
        ListNode * curr = head;
        while(curr && second){
            resp->next = curr;
            curr = curr->next;
            resp = resp->next;
            resp->next = second;
            second = second->next;
            resp = resp->next;
        }
        if(second){
            resp->next = second;
        }
        if(curr){
            resp->next = curr;
        }
        swap(head, resphead->next);
        return;
    }
};