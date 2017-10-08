#include <iostream>
using namespace std;
struct node {
    int vertexNumber;
    node* next;
};
struct list {
    node* head;
};
struct graph {
    int V;
    list *array;
};
node* getNewNode(int dest)
{
    node* temp = new node();
    temp->vertexNumber = dest;
    temp->next = NULL;
    return temp;
}
graph* createGraph(int v)
{
    graph* G = new graph();
    G->V = v;
    G->array = new list[v];
    for (int i = 0; i < v; i++) {
        G->array[i].head = NULL;
    }
    return G;
}
void insert(graph* G, int source, int destination) {
    node* temp = getNewNode(destination);
    temp->next = G->array[source].head;
    G->array[source].head = temp;

    temp = getNewNode(source);
    temp->next = G->array[destination].head;
    G->array[destination].head = temp;
}
void printGraph(graph* G) {
    for (int i = 0; i < G->V; i++) {
        node* temp = G->array[i].head;
        while (temp != NULL) {
            std::cout << temp->vertexNumber << '-';
            temp = temp->next;
        }
        std::cout << '\n';
    }
}
int main(int argc, char const *argv[]) {
    graph* G = createGraph(5);
    insert(G, 0, 3);
    insert(G, 0, 1);
    insert(G, 0, 4);
    insert(G, 1, 2);
    insert(G, 1, 3);
    insert(G, 1, 4);
    insert(G, 2, 3);
    insert(G, 3, 4);
    printGraph(G);
    return 0;
}
