#include <bits/stdc++.h>
using namespace std;
bool CheckSumPairs(int arr[], int n, int k, int m)
{
    /*Write your code here.
    *Don't write main().
    *Don't take input, it is passed as function argument.
    *Don't print output.
    *Taking input and printing output is handled automatically.
    // */

    vector<int> map(k, 0);
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        map[arr[i] % k] = map[arr[i] % k] + 1;
    }
    for (int i = 0; i < k; i++)
    {
        if (map[i] == map[m - i] && i != (m - i))
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
    }
    if (m % 2 == 0 && map[m / 2] % 2 == 0)
    {
        return true;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k, m;
    cin >> k >> m;
    if (CheckSumPairs(arr, n, k, m))
        cout << "true";
    else
        cout << "false";
}
