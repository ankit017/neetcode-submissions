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
    ListNode* reverse(ListNode* head) {
        ListNode *curr, *prev=nullptr, *next;
        curr=head;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    void merge(ListNode* list1, ListNode* list2) {
        ListNode node;
        ListNode* dummy = &node;
        ListNode* tail = dummy;
        int count = 0;
        while(list1 && list2) {
            if(count%2 == 0) {
                tail->next = list1;
                list1=list1->next;
            }
            else {
                tail->next = list2;
                list2=list2->next;
            }
            tail = tail->next;
            count++;
        }

        if(list1) {
            tail->next=list1;
        }
    }
    void reorderList(ListNode* head) {
        ListNode *slow, *fast, *second;

        slow=fast=head;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        second=slow->next;
        slow->next = nullptr;

        second = reverse(second);
        merge(head, second);
    }
};
