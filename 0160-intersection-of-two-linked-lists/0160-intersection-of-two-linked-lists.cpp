/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode*helper(ListNode *headA, ListNode *headB, int diff){
        ListNode*t1 = headA;
        while(diff-- && t1){
            t1 = t1->next;
        }
        ListNode*t2 = headB;
        while(t1 && t2){
            if(t1 == t2){
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1;
        t1 = headA;
        int len1, len2;
        while(t1){
            t1 = t1->next;
            len1++;
        }
        t1 = headB;
        while(t1){
            t1 = t1->next;
            len2++;
        }
        int diff = abs(len1-len2);
        if(len1 > len2){
            return helper(headA, headB, diff);
        } 
        return helper(headB, headA, diff);
    }
};