#include <iostream>
using namespace std;
int n;
struct ListNode {
    ListNode* next;
    int data;
};
ListNode* head;
struct ListBlock {
    ListBlock* next;
    ListNode* head;
    int nodes_quantity;
};
ListBlock* blockhead;
ListBlock* getNewBlock()
{
    ListBlock* block = new ListBlock();
    block->nodes_quantity = 0;
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
void insert(int x,int k) {
    ListNode* temp1,temp2;
    if (blockhead == NULL) {
        blockhead = getNewBlock();
        blockhead->head = getNewNode(x);
        blockhead->head->next = head;
        blockhead->nodes_quantity ++;
    }
    else
    {
        if (k == 0) {
            temp1 = blockhead->head;
            temp2 = temp1->next;
            temp1->next = getNewNode(x);
            temp1->next->next = temp2;
            head = temp1->next;
        }
        else
        {
            searchElement(k,&temp3,&temp1);
            temp2 = temp1;
            while (temp2->next != temp1) {
                temp2 = temp2->next;
            }
            temp2->next = getNewNode(x);
            temp2->next->next = temp1;
            temp3->nodes_quantity++;
        }
    }
}
void searchElement(int k,ListBlock** block_position,ListNode** node_position) {
    int j = (k + n - 1)/n;
    ListBlock* temp1 = blockhead;
    while (j != 0) {
        temp1 = temp1->next;
        --j;
    }
    *block_position = temp1;
    k = k % n;
    if (k == 0) {
        k = n;
    }
    k = temp1->nodes_quantity + 1 - k;
    while (k != 0) {
        temp2 = temp2->next;
        --k;
    }
    *node_position = temp2;
}
