class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
private: 
    unordered_map<int, Node*> cache;
    int capacity;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node* node = cache[key];

            // detach node from place in line
            if (node->prev) {
                // if not first node, set prev next to point to next
                node->prev->next = node->next;
            }
            if (node->next) {
                // if not end node, set next prev to point to prev
                node->next->prev = node->prev;
            }

            // retach at the front
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;

            return cache[key]->val;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            get(key);
            cache[key]->val = value;
            return;
        } else {
            Node* node = new Node(key, value);
            cache[key] = node;
            
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            

            capacity--;
        }

        if (capacity < 0) {
            cache.erase(tail->prev->key);

            Node* lru = tail->prev;
            lru->prev->next = tail;
            tail->prev = lru->prev;
        }
    }
};
