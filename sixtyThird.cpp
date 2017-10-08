#include <iostream>
using namespace std;
struct graph {
    int V;
    int E;
    int **A;
};
graph* matrixCreation()
{
    int u, v;
    graph* G = new graph();
    std::cout << "Enter number of vertices and edges" << '\n';
    cin >> G->V >> G->E;
    G->A = new int[G->V][G->E];
    for (int i = 0; i < G->V; i++) {
        for (int j = 0; j < G->V; j++) {
            G->A[i][j] = 0;
        }
    }
    for (int i = 0; i < G->E; i++) {
        cin >> "Enter Edge ">> u >> v;
        G->A[u][v] = 1;
        G->A[v][u] = 1;
    }
}
