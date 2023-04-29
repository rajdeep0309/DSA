#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    unordered_map<int, int> store; // make a map to store the frequency of elements instead of index
    vector<pair<int, int>> temp;

    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        int key = target - arr[i];

        if (store[target - arr[i]] > 0)
        { // check if frequency of 'key' is greater than zero
            pair<int, int> ans;
            ans.first = arr[i];
            ans.second = key;
            temp.push_back(ans);
            // decrease the freqency of the 'key' after you have selected it
            store[target - arr[i]]--;
        }
        else
        {
            store[arr[i]]++; // increase the frequency of arr[i] by store[arr[i]]++
        }
    }
    if (temp.size() != 0)
    {
        return temp;
    }
    else
    {
        pair<int, int> ans;
        ans.first = -1;
        ans.second = -1;
        temp.push_back(ans);
        // return 'temp'  here
        return temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vector<pair<int, int>> ans = twoSum(v, target, n);
        for (auto i : ans)
        {
            if (i.first < i.second)
                cout << i.first << " " << i.second << "\n";
            else
                cout << i.second << " " << i.first << "\n";
        }
    }
}