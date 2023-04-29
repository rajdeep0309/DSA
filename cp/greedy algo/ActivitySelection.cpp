#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
int maxActivitySub(vector<pair<int, int>> input, int n)
{
    sort(input.begin(), input.end(), cmp);
    int maxi = 0, last = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (input[i].first >= last)
        {
            maxi++;
            last = input[i].second;
        }
    }
    return maxi;
}
int main()
{

    // write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> acti;
        // first=start time     second=end time
        cin >> acti.first >> acti.second;
        input[i] = acti;
    }
    cout << maxActivitySub(input, n) << endl;
    return 0;
}