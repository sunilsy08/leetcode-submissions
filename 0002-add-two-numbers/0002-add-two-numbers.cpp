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
        
        ListNode* dummy = new ListNode(0);
        ListNode*tail = dummy;

        ListNode* num1 = l1, *num2 = l2;
        int carry = 0;
        while(num1 || num2){
            int a = num1 ? num1->val : 0;
            int b = num2 ? num2->val : 0;
            int sum = a + b + carry;
            carry = sum/10;
            sum = sum%10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            num1 = num1 ? num1->next : num1;
            num2 = num2 ? num2->next : num2;
        }
        if(carry){
            tail->next = new ListNode(carry);
        }
        return dummy->next;
    }
};