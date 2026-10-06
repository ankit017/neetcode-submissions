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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode node;
        ListNode* dummy = &node;
        ListNode* tail = dummy;
        int count=0;
        ListNode* curr = head;
        while(curr) {
            count++;
            curr=curr->next;
        }

        curr=head;

        if(count-n == 0)
        return head->next;

        for(int i=0; i<count-n; i++) {
            tail->next = curr;
            curr=curr->next;
            tail = tail->next;
        }

        tail->next=curr->next;
        curr->next=nullptr;
        return head;
    }
};
