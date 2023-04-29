/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5
*/

#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;
/*
//brute force
int stairCase(int n)
{
    if(n==0)
     return 1;
    else if (n<0)
     return 0;
    return stairCase(n-1)+stairCase(n-2)+stairCase(n-3);
}
*/
/*
//memoization
int helper(int n,int*ans)
{
    if(n<0)
     return 0;
    if(n==0)
     return 1;
    int  factor = pow(10, 9) + 7;
    if (ans[n] != -1) {
      return ans[n];
     }
     int  ouput=((helper(n-1,ans)%factor)+(helper(n-2,ans)%factor))%factor+(helper(n-3,ans)%factor);

     ans[n]=ouput %factor;
    // ans[n]=fmod(ouput,factor);
     return ans[n];
}
int stairCase(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }

    return helper(n,ans);
}
*/

// using DP
int factor = pow(10, 9) + 7;
int stairCase(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        ans[i] = ((ans[i - 1] % factor + ans[i - 2] % factor) % factor + ans[i - 3]) % factor;
    }

    return fmod(ans[n], factor);
}

int main()
{

    // write your code here
    int t;
    cout << "number of case";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "enter the number of stair:";
        cin >> n;
        cout << stairCase(n);
        cout << endl;
    }
    return 0;
}