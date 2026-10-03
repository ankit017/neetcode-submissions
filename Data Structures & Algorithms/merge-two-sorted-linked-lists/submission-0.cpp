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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* finalList=nullptr, *newHead=nullptr;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                if(finalList == nullptr) {
                    finalList = list1;
                    newHead = list1;
                }
                else {
                    finalList->next = list1;
                }
                finalList=list1;
                list1=list1->next;
            }
            else {
                if(finalList == nullptr) {
                    finalList = list2;
                    newHead = list2;
                }
                else {
                    finalList->next = list2;
                }
                finalList=list2;
                list2=list2->next;
            }           
        }
        while(list1) {
            if(finalList == nullptr) {
                newHead = list1;
                finalList = list1;
            }
            else {
                finalList->next = list1;
            }
            finalList = list1;
            list1=list1->next;
        }

        while(list2) {
            if(finalList == nullptr) {
                finalList = list2;
                newHead = list2;
            }
            else {
                finalList->next = list2;
            }
            finalList = list2;
            list2=list2->next;
        }
        return newHead;
        
    }
};
