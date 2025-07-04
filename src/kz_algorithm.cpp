#include "kz_algorithm.h"
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

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int n = nums.size();
    std::vector<std::vector<int>> ans;
    while (left < n - 2)
    {
        if (left > 0 && nums[left] == nums[left - 1])
        {
            left++;
            continue; // Skip duplicates
        }
        int mid = left + 1;
        int right = n - 1;
        while (mid < right)
        {
            int sum = nums[left] + nums[mid] + nums[right];
            if (sum < 0)
            {
                mid++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                ans.push_back({nums[left], nums[mid], nums[right]});
                while (mid < right && nums[mid] == nums[mid + 1])
                {
                    mid++; // Skip duplicates
                }
                while (mid < right && nums[right] == nums[right - 1])
                {
                    right--; // Skip duplicates
                }
                mid++;
                right--;
            }
        }
        left++;
    }
    return ans;
}

std::vector<int> findKDistantIndices(std::vector<int> &nums, int key, int k)
{
    std::vector<int> result;
    int n = nums.size();
    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == key)
        {
            l = std::max(r, i - k);
            r = std::min(static_cast<int>(nums.size() - 1), i + k) + 1;
            for (int j = l; j < r; j++)
            {
                result.push_back(j);
            }
        }
    }
    return result;
}

int longestSubsequence(std::string s, int k)
{
    return 0;
}

bool comp(std::pair<int, int> &a, std::pair<int, int> &b)
{
    return a.first > b.first;
}

bool comp2(std::pair<int, int> &a, std::pair<int, int> &b)
{
    return a.second < b.second;
}

std::vector<int> maxSubsequence(std::vector<int> &nums, int k)
{
    int n = nums.size();
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; i++)
    {
        pairs.push_back({nums[i], i});
    }
    std::sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
              { return a.first > b.first; });
    std::vector<std::pair<int, int>> partAns;
    for (int i = 0; i < k; i++)
    {
        partAns.push_back(pairs[i]);
    }
    std::sort(partAns.begin(), partAns.end(), [](const auto &a, const auto &b)
              { return a.second < b.second; });
    std::vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(partAns[i].first);
    }
    return ans;
}

int maxArea(std::vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right)
    {
        int curArea = abs(left - right) * std::min(height[left], height[right]);
        maxArea = std::max(maxArea, curArea);
        if (height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return maxArea;
}

LRUCache::LRUCache(int capacity) : capacity(capacity), size(0)
{
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
    ListNode *dummyHead = new ListNode();

    ListNode *cur = head;
    while (cur)
    {
        ListNode *next = cur->next;
        ListNode *preFirst = dummyHead->next;
        dummyHead->next = cur;
        cur->next = preFirst;
        cur = next;
    }
    return dummyHead->next;
}

int rob(std::vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int p = nums[0];
    int pp = std::max(nums[1], nums[0]);
    for (int x = 2; x < nums.size(); x++)
    {
        int cur = std::max(pp, p + nums[x]);
        p = pp;
        pp = cur;
    }
    return pp;
}

int deleteAndEarn(std::vector<int> &nums)
{
    std::map<int,int> countMap;
    for (int num : nums)
    {
        countMap[num]++;
    }
    int maxNum = 0;
    for (const auto &pair : countMap)
    {
        maxNum = std::max(maxNum, pair.first);
    }
    std::vector<int> dp(maxNum + 1, 0);
    for (const auto &pair : countMap)
    {
        int num = pair.first;
        int count = pair.second;
        dp[num] = num * count;
    }
    for (int i = 2; i <= maxNum; i++)
    {
        dp[i] = std::max(dp[i - 1], dp[i] + dp[i - 2]);
    }
    return dp[maxNum];
}

