/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
*/
#include <climits>
#include <iostream>
using namespace std;
// namespace std;

void helper(int n, int *ans)
{
    // ans[0]=0;
    ans[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        int x = INT_MAX, y = INT_MAX, z = INT_MAX;
        if (i % 3 == 0)
        {
            x = ans[i / 3];
        }
        if (i % 2 == 0)
        {
            y = ans[i / 2];
        }
        z = ans[i - 1];
        ans[i] = min(x, min(y, z)) + 1;
    }
}
int countStepsToOne(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    helper(n, ans);
    return ans[n];
}
int main()
{
    int n;
    cout << "enter the num:";
    cin >> n;
    cout << countStepsToOne(n);
}