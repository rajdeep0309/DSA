#include <iostream>
using namespace std;
// void print(int **edges, int n, int sv, bool *visited)
// {
//     cout << sv << endl;
//     visited[sv] = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == sv)
//         {
//             continue;
//         }
//         if (edges[sv][i] == 1)
//         {
//             if (visited[i])
//             {
//                 continue;
//             }
//             print(edges, n, i, visited);
//         }
//     }
// }
// ...................................................................
void print(int **edges, int v, int sv, bool *visited)
{
    cout << sv;
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, v, i, visited);
        }
    }
}
// ...................................................................
int main()
{
    int v, e;
    cout << "enter no of the vertiecs && edges:" << endl;
    cin >> v >> e;
    // create ajusence matrix
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    // connect the  vertices
    for (int i = 0; i < e; i++)
    {
        int v1, u;
        cout << i + 1 << ":enter the vertiecs to connect:" << endl;
        cin >> v1 >> u;
        edges[v1][u] = edges[u][v1] = 1;
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    print(edges, v, 0, visited);
}