/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note
Strings don't contain spaces
You need to find the edit distance from input string1 to input string2.
Input Format :
The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.
Output Format :
The first and only line of output contains the edit distance value between the given strings.
Constraints :
1<= m,n <= 10
Time Limit: 1 second
Sample Input 1 :
abc
dc
Sample Output 1 :
2
*/
#include <cstring>
#include <iostream>
using namespace std;
/*using DP*/
int editDistance(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    output[0][0] = 0;
    // initialize independent rows &coloumn
    // rowwise(1st row)

    for (int j = 1; j <= n; j++)
    {
        output[0][j] = j;
    }
    // coloumn wise(1st cloumn)
    for (int i = 1; i <= m; i++)
    {
        output[i][0] = i;
    }
    // intialize dependent matrix
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                output[i][j] = min(output[i - 1][j - 1], min(output[i][j - 1], output[i - 1][j])) + 1;
            }
        }
    }
    return output[m][n];
}
/*memoisation*/
/*
int editDistance(string s1, string s2, int **output)
{
    // Write your code here
    int i = s1.size();
    int j = s2.size();
    // base case
    if (s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }

    // check
    if (output[i][j] != -1)
    {
        return output[i][j];
    }
    if (s1[0] == s2[0])
    {
        int ans = editDistance(s1.substr(1), s2.substr(1), output);
        output[i][j] = ans;
        // return ans;
    }
    else
    {
        // insert
        int x = editDistance(s1.substr(1), s2, output);
        // delete
        int y = editDistance(s1, s2.substr(1), output);
        // repalce
        int z =
            editDistance(s1.substr(1), s2.substr(1), output);
        // future use
        output[i][j] = min(x, min(y, z)) + 1;
    }
    return output[i][j];
}

int editDistance(string s1, string s2)
{
    int **output = new int *[s1.size() + 1];
    for (int i = 0; i <= s1.size(); i++)
    {
        output[i] = new int[s2.size() + 1];
        for (int j = 0; j <= s2.size(); j++)
        {
            output[i][j] = -1;
        }
    }

    int ans = editDistance(s1, s2, output);
    return output[s1.size()][s2.size()];
}
*/
/*brute force */
/*
int editDistance(string s1, string s2)
{
    // Write your code here
    // base case
    if (s1.size() == 0 || s2.size() == 0)
    {
        return max(s1.size(), s2.size());
    }

    // check
    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    // insert
    int x = editDistance(s1.substr(1), s2);
    // delete
    int y = editDistance(s1, s2.substr(1));
    // repalce
    int z = editDistance(s1.substr(1), s2.substr(1));
    return min(x, min(y, z)) + 1;
}
*/

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}