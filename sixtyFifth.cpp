#include <iostream>
#include <queue>
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
    list* array;
};
queue<int> Q;
int visited[5];
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
void BFS(graph* G, int u) {
    Q.push(u);
    visited[u] = 1;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        std::cout << u << ' ';
        
    }
}
