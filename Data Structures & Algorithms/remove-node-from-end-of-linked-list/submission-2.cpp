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
        int count = 0;
        ListNode* curr = head;

        while (curr) {
            count++;
            curr = curr->next;
        }

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 0; i < count - n; i++) {
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return dummy.next;
    }
};
