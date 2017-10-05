#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
struct node
{
int data;
node* right;
node* left;
int height;
};
queue<node*> Q;
int difference = 100;
int Height(node* temp)
{
if(temp == NULL)
return -1;
else
return temp->height;
}
node* getNewNode(int x)
{
node* temp = new node();
temp->data = x;
temp->right = NULL;
temp->left = NULL;
temp->height = 0;
return temp;
}
int Maximum(int a, int b)
{
return (a > b)? a:b;
}
node* rotateRight(node* X)
{
node* Y = X->left;
X->left = Y->right;
Y->right = X;
X->height = Maximum(Height(X->left), Height(X->right)) + 1;
Y->height = Maximum(Height(Y->left), X->height) + 1;
return Y;
}
node* rotateLeft(node* X)
{
node* Y = X->right;
X->right = Y->left;
Y->left = X;
X->height = Maximum(Height(X->left), Height(X->right)) + 1;
Y->height = Maximum(Height(Y->right), X->height) + 1;
return Y;
}
node* insert(node* temp, int x)
{
if(temp == NULL)
return getNewNode(x);
else if(temp->data > x)
temp->left = insert(temp->left , x);
else if(temp->data < x)
temp->right = insert(temp->right, x);
else
return temp;

temp->height = Maximum(Height(temp->left), Height(temp->right)) + 1;

int bal = Height(temp->left) - Height(temp->right);

if(bal > 1 && temp->left->data > x)
    return rotateRight(temp);
if (bal < -1 && temp->right->data < x)
    return rotateLeft(temp);
if (bal > 1 && temp->left->data < x) {
    temp->left = rotateLeft(temp->left);
    return rotateRight(temp);
}
if (bal < -1 && temp->right->data > x) {
    temp->right = rotateRight(temp->right);
    return rotateLeft(temp);
}
return temp;
}
int keyLevelOrder(node* t, int key)
{
node* temp;
node* mark;
if(t == NULL)
return 0;
Q.push(t);
while(!Q.empty())
{
temp = Q.front();
Q.pop();
if(abs(key - temp->data) < difference)
{
difference = abs(key - temp->data);
mark = temp;
}
if(temp->left != NULL)
Q.push(temp->left);
if(temp->right != NULL)
Q.push(temp->right);
}
return mark->data;
}
int main(int argc, char const *argv[]) {
    node* root = NULL;
    root = insert(root,5);
    root = insert(root,40);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,35);
    root = insert(root,25);
    std::cout << "The closest key is "<< keyLevelOrder(root, 34) << '\n';
    return 0;
}
