#include <iostream>
#include <vector>
class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node() {

        prev = nullptr;
        next = nullptr;
    };
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    };
};

class LRUCache {
    int capacity;
    int size;
    std::vector<Node*> cache = std::vector<Node*>(
        10001, nullptr); // Using a vector to store nodes for simplicity
    Node* dummyHead;     // Dummy head node
    Node* dummyTail = nullptr;

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        dummyHead = new Node();
    }

    int get(int key) {
        Node* node = this->getNode(key);
        if (node == nullptr) {
            return -1; // Key not found
        }
        return node->value;
    }

    void put(int key, int value) {
        Node* node = this->getNode(key);
        if (node != nullptr) {
            node->value = value; // Update the value if the key exists
            return;
        }
        node = new Node(key, value);
        Node* curFirst = this->dummyHead->next;
        node->next = curFirst;
        if (curFirst != nullptr) {
            curFirst->prev = node;
        }
        dummyHead->next = node;
        node->prev = dummyHead;
        cache[node->key] = node; // Add to cache
        if (dummyTail == nullptr) {
            dummyTail = node; // If this is the first node, set dummyTail
                    size++;

        } else if (size == capacity) {
            // Remove the least recently used node
            Node* toRemove = dummyTail;
            dummyTail = dummyTail->prev;
            if (dummyTail != nullptr) {
                dummyTail->next = nullptr;
            }
            cache[toRemove->key] = nullptr; // Remove from cache
            delete toRemove;                // Free memory of the removed node
        } else {
            size++;
        }
    }

private:
    void moveToHead(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        if (n != nullptr) {
            n->prev = p;
        }
        
        node->next = dummyHead->next;

        Node* preFirst = dummyHead->next;
        if (preFirst != nullptr) {
            preFirst->prev = node;
        }
        dummyHead->next = node;
        if (this->dummyTail == node) {
            this->dummyTail = node->prev;
        }
        node->prev = dummyHead;
    };
    Node* getNode(int key) {
        Node* node = (this->cache).at(key);
        if (node == nullptr) {
            return nullptr; // Key not found
        }
        this->moveToHead(node);
        return node;
    };
};
void test2();
int main(int, char**){
    std::cout << "Hello, World!" << std::endl;

    test2();
}
void test2 () {
    LRUCache *lru = new LRUCache(1);
    lru->put(2, 1);
    std::cout << lru->get(2) << std::endl; // returns
    lru->put(3, 2); // evicts key 2
    std::cout << lru->get(2) << std::endl; // returns -
    std::cout << lru->get(3) << std::endl; // returns
    system("pause");
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */