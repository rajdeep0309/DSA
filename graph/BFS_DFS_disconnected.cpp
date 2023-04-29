#include <queue>
#include <iostream>
using namespace std;
void printBFS(bool **edges, int v, int sv, bool *visited)
{
    queue<int> pendingEdges;
    pendingEdges.push(sv);
    visited[sv] = true;
    while (!pendingEdges.empty())
    {
        /* code */
        int currentEdge = pendingEdges.front();
        pendingEdges.pop();
        cout << currentEdge << endl;
        for (int i = 0; i < v; i++)
        {
            if (i == currentEdge)
            {
                continue;
            }
            if (edges[currentEdge][i] == true && !visited[i])
            {
                pendingEdges.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(bool **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}
void printDFS(bool **edges, int v, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == true && !visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
}
void DFS(bool **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
    delete[] visited;
}
int main()
{
    int v, e;
    cout << "enter the no of vertices and edges" << endl;
    cin >> v >> e;
    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new bool[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = false;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cout << "enter the 1st edge & 2nd edge to connect:" << endl;
        cin >> v1 >> v2;
        edges[v1][v2] = edges[v2][v1] = true;
    }
    cout << "BFS" << endl;
    BFS(edges, v);
    cout << "DFS" << endl;
    DFS(edges, v);
}