/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
*/
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;
int minCostPath(int **input, int m, int n, int i, int j)
{
    // Write your code here

    if (i == m - 1 && j == n - 1)
        return input[i][j];
    if (i > m - 1 || j > n - 1)
    {
        return INT_MAX;
    }
    int x = minCostPath(input, m, n, i + 1, j + 1);
    int y = minCostPath(input, m, n, i + 1, j);
    int z = minCostPath(input, m, n, i, j + 1);
    return input[i][j] + (min(x, min(y, z)));
}
int minCostPath(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}
int main()
{
    int **arr, n, m;
    cout << "enter the no of row&column:";
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}