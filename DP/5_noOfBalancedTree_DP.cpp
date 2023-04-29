/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.
Output Format :
The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.
Constraints :
1 <= h <= 24
Time Limit: 1 sec
*/
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
/*
int balancedBTs(int n) {
    // Write your code here
    if(n<2)
    {
        return 1;
    }
    int factor=pow(10,9)+7;
    long long int n0=0,n1=1,n2;
    for(int i=2;i<=n;++i)
    {

      n2 = (n1 * ((2 * n0) % factor + n1) % factor) % factor;
      n0 = n1;
      n1 = n2;
    }
    return n2;
}
*/

int balancedBTs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    vector<long long int> ans(n + 1);
    int factor = pow(10, 9) + 7;
    ans[0] = 1;
    ans[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        long long int temp = ((ans[i - 1] * ans[i - 1]) % factor);
        long long int temp1 = ((2 * ans[i - 1] * ans[i - 2]) % factor);
        ans[i] = (temp + temp1) % factor;
    }
    return ans[n];
}
int main()
{
    int n;
    cout << "enter the height of the tree";
    cin >> n;
    cout << balancedBTs(n);
}
