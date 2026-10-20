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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

        ListNode tmp;
        ListNode* head=&tmp;

        ListNode* tail = head;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        const int k = lists.size();

        for(int i=0; i<k; i++) {
            ListNode* node = lists[i];
            if(node!=nullptr) {
                pq.push({node->val, node});
            }
            
        }

        while(!pq.empty()) {
            auto it = pq.top();
            ListNode* curr = it.second;
            ListNode* next = it.second->next;

            tail->next = curr;
            tail = tail ->next;

            pq.pop();

            if(next!=nullptr) {
                pq.push({next->val, next});
            }

        }

        return head->next;
        
    }
};