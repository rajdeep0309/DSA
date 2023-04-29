#include <queue>
#include <iostream>
using namespace std;
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
        cin >> v1 >> v2;
        edges[v1][v2] = edges[v2][v1] = true;
    }
    bool *visited = new bool[e];
    for (int i = 0; i < e; i++)
    {
        visited[i] = false;
    }
    queue<int> list;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            list.push(i);
            visited[i] = true;
        }
        while (!list.empty())
        {
            int front = list.front();
            list.pop();
            cout << front << " ";
            for (int j = 0; j < v; j++)
            {
                if (edges[front][i] && !visited[i])
                {
                    list.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}