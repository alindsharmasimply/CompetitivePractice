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
