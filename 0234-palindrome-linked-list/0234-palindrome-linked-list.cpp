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
    ListNode* reverse(ListNode*head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode*revhead = reverse(head->next);
        if(head != NULL && head->next !=NULL) {
            head->next->next = NULL;
        }
        head->next = NULL;
        return revhead;
    }
    
    ListNode* revList(ListNode* head) {
        ListNode* curr = head;
        ListNode* nextptr,*prev = NULL;
        
        while(curr) {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode* fast = head;
        ListNode* slow = head;
        int count = 0;
        while(slow) {
            slow = slow->next;
            count++;
        }
        int len1 = count/2;
        
        slow = head;
        while(len1) {
            len1--;
            fast = slow;
            slow = slow->next;
        }
        fast->next = NULL;
        ListNode* revlist = revList(slow);
        
        ListNode*temp = revlist;
        while(temp) {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        fast = head;
        len1 = count/2;
        fast = head;
        while(len1-- && fast && slow) {
            if(fast->val != revlist->val)
                return false;
            revlist = revlist->next;
            fast = fast->next;
        }
        return true;
        
    }
};