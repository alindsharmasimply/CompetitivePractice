#include <iostream>
using namespace std;
struct node
 {
    int data;
    node* next;
};
node* head;
node* getNewNode(int x)
{
    node* temp = new node();
    temp->data = x;
    temp->next = NULL;
    return temp;
}
void insert(int n,int x) {
    node* temp = getNewNode(x);
    node* temp1 = head;
    if (n==1) {
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 0; i < n - 2; i++) {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void display(/* arguments */) {
    node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
}
void problem(){
    node* prevNode = NULL;
    node* currentNode = head;
    node* nextNode = head->next;
    while (currentNode != NULL) {
        if (currentNode->data % 2 == 0) {
            nextNode = currentNode->next;
            currentNode->next = head;
            head = currentNode;
            currentNode = nextNode;
            if (prevNode == NULL) {
                prevNode = head;
            }
            else{
                prevNode->next = nextNode;
            }
        }
        else{
            currentNode = currentNode->next;
            nextNode = nextNode->next;
            if (prevNode == NULL) {
                prevNode = head;
            }
            else{
                prevNode = prevNode->next;
            }
        }
    }
}
    int main(int argc, char const *argv[]) {
        head = NULL;
        insert(1,3);
        insert(2,4);
        insert(3,5);
        insert(4,6);
        insert(5,7);
        insert(6,8);
        insert(7,9);
        display();
        problem();
        std::cout << '\n';
        display();
        return 0;
    }
