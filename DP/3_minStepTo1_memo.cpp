// memoization
#include <iostream>
#include <climits>
using namespace std;
int helperCount(int n, int *ans)
{
    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if (n <= 1)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    if (n % 3 == 0)
    {
        ans1 = helperCount(n / 3, ans);
    }
    if (n % 2 == 0)
    {
        ans2 = helperCount(n / 2, ans);
    }
    ans3 = helperCount(n - 1, ans);
    int output = min(ans1, min(ans2, ans3)) + 1;
    ans[n] = output;
    return ans[n];
}
int countStepsToOne(int n)
{
    // Write your code here
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    // int count = 0;
    return helperCount(n, ans);
}
int main()
{
    int n;
    cout << "enterr the number:";
    cin >> n;
    cout << countStepsToOne(n);
}