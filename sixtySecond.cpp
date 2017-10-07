#include <iostream>
using namespace std;
struct heap {
    int *array;
    int count;
    int capacity;
    int heap_type;
};
heap* create(int cap, int type)
{
    heap* temp = new heap();
    temp->heap_type = type;
    temp->count = 0;
    temp->capacity = cap;
    temp->array = new int[cap];
    return temp;
}
heap* h = create(3,1);
int parent(int i)
{
    return (i-1)/2;
}
int left(int i)
{
    return (2*i) + 1;
}
int right(int i)
{
    return (2*i) + 2;
}
int Maximum(heap* temp)
{
    return temp->array[0];
}
void resize(heap* temp) {
    int *oldArray = temp->array;
    temp->array = new int[temp->capacity * 2];
    for (int i = 0; i < temp->capacity; i++) {
        temp->array[i] = oldArray[i];
    }
    temp->capacity *= 2;
    delete oldArray;
}
void insert(heap* temp, int x) {
    int i;
    if (temp->count == temp->capacity) {
        resize(temp);
    }
    i = temp->count;
    temp->count++;
    while (i >= 0 && x > temp->array[(i-1)/2]) {
        temp->array[i] = temp->array[(i-1)/2];
        i = (i-1)/2;
    }
    temp->array[i] = x;
}
void display(heap* temp)
{
    for (int i = 0; i < temp->count; i++) {
        std::cout << temp->array[i] << ' ';
    }
}
int main(int argc, char const *argv[]) {
    insert(h, 16);
    insert(h, 14);
    insert(h, 9);
    insert(h, 12);
    insert(h, 8);
    insert(h, 10);
    insert(h, 31);
    insert(h, 3);
    insert(h, 1);
    insert(h, 5);
    insert(h, 7);
    insert(h, 19);
    display(h);
    return 0;
}
