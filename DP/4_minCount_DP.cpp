/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4
*/
#include <cmath>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

/*
int helper(int n)
{
    if(sqrt(n)-floor(sqrt(n))==0)
    return 1;
    if(n<=3)
    {
        return n;
    }
    int x=INT_MAX;
    for(int i=1;i<=sqrt(n);i++)
    {
     x=fmin(n,helper(n-(i*i)))+1;
    }
    return x;
}
*/

int minCount(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    for (int i = 4; i <= n; i++)
    {

        for (int j = 1; j <= sqrt(i); j++)
        {
            if (sqrt(i) - floor(sqrt(n)) == 0)
                ans[i] = 1;
            else
            {
                ans[i] = fmin(n, 1 + ans[n - j * j]);
            }
        }
    }
    return ans[n];
}

int main()
{
    int n;
    cout << "enter the number:";
    cin >> n;
    cout << minCount(n);
}