#include <iostream>
using namespace std;
struct ListNode {
    ListNode* next;
    int data;
};
struct ListBlock {
    ListBlock* next;
    ListNode* head;
    int nodes_quantity;
};
ListBlock* getNewBlock(x)
{
    ListBlock* block = new ListBlock();
    block->nodes_quantity = x;
    block->next = NULL;
    block->head = NULL;
    return block;
}
ListNode* getNewNode(y)
{
    ListNode* temp = new ListNode();
    temp->data = y;
    temp->next = NULL;
    return temp;
}
