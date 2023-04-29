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
input:4 4
1 7 9 2
8 6 3 2
1 6 7 8
2 9 8 2

*/
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }
    // independent rows & column
    // fill the destination box value
    output[n - 1][m - 1] = input[n - 1][m - 1];

    // lat row filled right to left
    for (int j = m - 2; j >= 0; j--)
    {
        output[n - 1][j] = input[n - 1][j] + output[n - 1][j + 1];
    }
    // last column filled bottom to upward
    for (int i = n - 2; i >= 0; i--)
    {
        output[i][m - 1] = input[i][m - 1] + output[i + 1][m - 1];
    }
    // dependent row &column
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i + 1][j], min(output[i][j + 1], output[i + 1][j + 1])) + input[i][j];
        }
    }

    return output[0][0];
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