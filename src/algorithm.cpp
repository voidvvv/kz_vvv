#include "algorithm.h"
#include <iostream>

int add(int a, int b)
{
    return a + b;
}

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> ans;
    std::map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if (map.find(complement) != map.end())
        {
            ans.push_back(map[complement]);
            ans.push_back(i);
            return ans;
        }
        map[nums[i]] = i;
    }
    return ans;
}

int trap(std::vector<int> &height)
{
    int n = height.size();
    if (n == 0)
        return 0;
    int left = 0;
    int right = n - 1;
    int leftMax = height[left], rightMax = height[right];
    int waterTrapped = 0;
    while (left < right)
    {
        if (leftMax < rightMax)
        {
            left++;
            leftMax = std::max(leftMax, height[left]);
            waterTrapped += leftMax - height[left];
        }
        else
        {
            right--;
            rightMax = std::max(rightMax, height[right]);
            waterTrapped += rightMax - height[right];
        }
    }
    return waterTrapped;
}

void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return;
    int n = matrix[0].size();
    std::vector<bool> rows(m);
    std::vector<bool> cols(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for (int a = 0; a < m; a++)
    {
        if (rows[a])
        {
            for (int b = 0; b < n; b++)
            {
                matrix[a][b] = 0;
            }
        }
    }

    for (int b = 0; b < n; b++)
    {
        if (cols[b])
        {
            for (int a = 0; a < m; a++)
            {
                matrix[a][b] = 0;
            }
        }
    }
}

LRUCache::LRUCache(int capacity) : capacity(capacity), size(0)
{
    dummyHead = new Node();
    dummyTail = nullptr;
}

int LRUCache::get(int key)
{
    Node *node = this->getNode(key);
    if (node == nullptr)
    {
        return -1; // Key not found
    }
    return node->value;
}

Node *LRUCache::getNode(int key)
{
    Node *node = (this->cache).at(key);
    if (node == nullptr)
    {
        return nullptr; // Key not found
    }
    this->moveToHead(node);
    return node;
}

Node::Node(int k, int v)
{
    key = k;
    value = v;
    prev = nullptr;
    next = nullptr;
}

Node::Node()
{

    prev = nullptr;
    next = nullptr;
}

void LRUCache::moveToHead(Node *node)
{
    Node *p = node->prev;
    Node *n = node->next;

    p->next = n;
    if (n != nullptr)
    {
        n->prev = p;
    }
    node->prev = dummyHead;
    node->next = dummyHead->next;

    Node *preFirst = dummyHead->next;
    if (preFirst != nullptr)
    {
        preFirst->prev = node;
    }
    dummyHead->next = node;
    if (this->dummyTail == node)
    {
        this->dummyTail = p->next;
    }
}

void LRUCache::put(int key, int value)
{
    Node *node = this->getNode(key);
    if (node != nullptr)
    {
        node->value = value; // Update the value if the key exists
        return;
    }
    node = new Node(key, value);
    Node *curFirst = this->dummyHead->next;
    node->next = curFirst;
    if (curFirst != nullptr)
    {
        curFirst->prev = node;
    }
    dummyHead->next = node;
    node->prev = dummyHead;
    cache[node->key] = node; // Add to cache
    if (dummyTail == nullptr)
    {
        dummyTail = node; // If this is the first node, set dummyTail
        size++;
    }
    else if (size == capacity)
    {
        // Remove the least recently used node
        Node *toRemove = dummyTail;
        dummyTail = dummyTail->prev;
        if (dummyTail != nullptr)
        {
            dummyTail->next = nullptr;
        }
        cache[toRemove->key] = nullptr; // Remove from cache
        delete toRemove;                // Free memory of the removed node
    }
    else
    {
        size++;
    }
}

ListNode *reverseList(ListNode *head)
{
    ListNode* dummyHead = new ListNode();

    ListNode* cur = head;
    while (cur) {
        ListNode* next = cur->next;
        ListNode *preFirst = dummyHead->next;
        dummyHead->next = cur;
        cur->next = preFirst;
        cur = next;
    }
    return dummyHead->next;
}