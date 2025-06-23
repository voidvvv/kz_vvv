#ifndef __LISTNODE_H__
#define __LISTNODE_H__
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
};

#endif // __LISTNODE_H__