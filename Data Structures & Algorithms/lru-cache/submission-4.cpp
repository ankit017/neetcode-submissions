class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int x, int y): key(x), val(y), next(nullptr), prev(nullptr) {}
    };
    int cacheSize;
    Node* head=nullptr, *tail=nullptr;

    unordered_map<int, Node*> cacheMap;
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        if(cacheMap.count(key)) {
            Node* node = cacheMap[key];
            if(!((node == head && node==tail) || node==head)) {
                node->prev->next = node->next;
                if(node != tail)
                node->next->prev = node->prev;
                else
                tail=tail->prev;

                head->prev=node;
                node->next=head;
                head=node;

            }
            return cacheMap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cacheMap.count(key)) {
            Node* node = cacheMap[key];
            node->val = value;
            if(node!=head) {
                node->prev->next = node->next;
                if(node!=tail)
                node->next->prev = node->prev;
                else
                tail=tail->prev;

                node->next=head;
                head->prev=node;
                head=node;
            }
            return;
        }
        Node *tmp = new Node(key, value);
        cacheMap[key]=tmp;
        
        if(head == nullptr && tail==nullptr) {
            head = tail = tmp;
            return;
        }

        tmp->next=head;
        tmp->prev=head->prev;
        head->prev=tmp;
        head=tmp;

        if(cacheMap.size() > cacheSize) {
            Node* prevTail = tail;
            tail->prev->next = tail->next;
            tail=tail->prev;
            cacheMap.erase(prevTail->key);
        }
        
    }
};
