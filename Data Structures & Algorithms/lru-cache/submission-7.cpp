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
    void swapHead(Node* node) {
        node->prev=nullptr;
        node->next=head;

        if(head!=nullptr)
        head->prev = node;
        head=node;
    }
    void refreshCache(Node* node, bool isNew) {
        if(head == nullptr && tail == nullptr) {
            head=tail=node;
            return;
        }
        if(isNew) {
            swapHead(node);
            return;
        }
        else if(node == head)
        return;
        else if(node == tail) {
            tail->prev->next = tail->next;
            tail = tail->prev;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        swapHead(node);
    }
    
    int get(int key) {
        if(cacheMap.count(key)) {
            Node* node = cacheMap[key];
            refreshCache(node, false);
            return cacheMap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cacheMap.count(key)) {
            Node* node = cacheMap[key];
            node->val = value;
            refreshCache(node, false);
            return;
        }
        Node *node = new Node(key, value);
        cacheMap[key]=node;
        
        refreshCache(node, true);

        if(cacheMap.size() > cacheSize) {
            Node* prevTail = tail;
            tail->prev->next = tail->next;
            tail=tail->prev;
            cacheMap.erase(prevTail->key);
        }
        
    }
};
