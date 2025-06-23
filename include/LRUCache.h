#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__
#include <iostream>
#include <vector>

class Node;
class LRUCache;

class LRUCache
{
    int capacity;
    int size;
    std::vector<Node *> cache = std::vector<Node *>(10001, nullptr); // Using a vector to store nodes for simplicity
    Node *dummyHead;                              // Dummy head node
    Node *dummyTail;

public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    void moveToHead(Node *node);
    Node* getNode(int key);
};

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node();
    Node(int k, int v);
};

#endif // __LRUCACHE_H__