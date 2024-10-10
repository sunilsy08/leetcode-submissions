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
    struct compare {
        bool operator()(pair<int, ListNode*> a, pair<int, ListNode*> b) {
            return a.first > b.first;  // For min-heap behavior
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<pair<int,ListNode*>>q;
     priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, compare> q;
        ListNode * dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int i=0; i< lists.size(); i++){
            if(lists[i]){
                q.push({lists[i]->val, lists[i]});
            }
        }

        while(!q.empty()){
            ListNode* nextNode = q.top().second;
            q.pop();
            tail->next = nextNode;
            tail = tail->next;

            if(nextNode->next){
                q.push({nextNode->next->val, nextNode->next});
            }
        }
        return dummy->next;
    }
};