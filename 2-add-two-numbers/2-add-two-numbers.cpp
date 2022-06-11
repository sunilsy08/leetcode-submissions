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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // case when either of them is null
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* ans = NULL;
        ListNode*final_ans;
        
        // now adding the numbers
        int carry = 0;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        
        while(h1 || h2) {
            int a = h1 ? h1->val : 0;
            int b = h2 ? h2->val : 0;
            
            int sum = a+ b + carry;
            carry = sum/10; 
            sum %= 10; 
            ListNode* temp = new ListNode(sum); 
            if(!ans) {
                ans = temp;
                final_ans = ans;
            }
            else {
                ans->next = temp;
                ans = ans->next;
            }
            if(h1) h1= h1->next;
            if(h2) h2 = h2->next;
        }
        ListNode* temp;
        if(!h1) temp = h2;
        if(!h2) temp = h1;

        if(!temp && carry != 0) {
            ListNode* last = new ListNode(carry);
            ans->next = last;
            return final_ans;
        }
        

        return final_ans;
    }
};