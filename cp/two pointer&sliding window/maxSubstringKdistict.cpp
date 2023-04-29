#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
#define ll long long
using namespace std;

void solve()
{
    int n, k;
    cout << "enter the number:" << endl;
    cin >> n;
    cout << "enter the k:" << endl;
    cin >> k;
    int maxi = INT_MIN;
    int curr_total = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            curr_total += arr[i];
        }
        else if (i == k - 1)
        {
            maxi = max(maxi, curr_total);
        }
        else if (i >= k)
        {
            curr_total += arr[i];
            curr_total -= arr[i - k];
            maxi = max(maxi, curr_total);
        }
    }
    cout << "max k sum" << maxi << endl;
}
int main()
{

    int t;
    cout << "enter case number:" << endl;
    cin >> t;
    while (t--)
    {
        //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}