/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> originalListMap;
        unordered_map<int, Node*> newListMap;

        Node node(0);
        Node* prev = &node;
        Node* curr=head;
        int index=0;
        Node* newHead=nullptr;
        while(curr != nullptr) {
            originalListMap[curr]= index;
            Node* tmp = new Node(curr->val);
            if(newHead == nullptr) {
                newHead = tmp;
            }
            newListMap[index]= tmp;
            curr=curr->next;
            prev->next = tmp;
            prev=tmp;
            index++;
        }

        Node* list1=head;
        Node* list2 = newHead;

        while(list1!=nullptr && list2!=nullptr) {
            if(list1->random == nullptr)
            list2->random = nullptr;
            else {
                int randomIndex = originalListMap[list1->random];
                list2->random = newListMap[randomIndex];
            }
            
            list1=list1->next;
            list2=list2->next;
        }
        return newHead;
    }
};
