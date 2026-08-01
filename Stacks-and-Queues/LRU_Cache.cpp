/*
LRU Cache

Approach:
- Use a Doubly Linked List to maintain the order of recently used elements.
- The most recently used (MRU) node is kept next to the head.
- The least recently used (LRU) node is kept just before the tail.
- Use an unordered_map to map each key to its corresponding node in O(1).

Operations:
- get(key):
  - If the key exists, move the node to the front and return its value.
  - Otherwise, return -1.

- put(key, value):
  - If the key already exists, remove the old node.
  - If the cache is full, remove the least recently used node.
  - Insert the new node at the front.

Time Complexity:
- get()  : O(1)
- put()  : O(1)

Space Complexity:
- O(capacity)
*/

// Code :-

class LRUCache {
public:
class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
     int cap;
    unordered_map<int, Node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int res = resNode->val;
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */