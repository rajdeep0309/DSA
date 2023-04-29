#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    double frac1 = (double)(p1.first / p1.second), frac2 = (double)(p2.first / p2.second);
    return (frac1 > frac2);
}
void fracKnapsack(vector<pair<int, int>> input, int n, int w)
{
    sort(input.begin(), input.end(), cmp);

    double total = 0.00000;
    int curWeight = 0;

    for (int i = 0; i < n; i++)
    {

        if (input[i].second + curWeight < w)
        {

            total += input[i].first;
            curWeight += input[i].second;
        }
        else
        {
            int rem = (w - curWeight);
            total += input[i].first * ((double)rem / input[i].second);
            break;
        }
    }
    cout << total << endl;
    double ans = 2.0;

    cout << (double)ans + 2.0 << endl;
    // return total;
}

int main()
{

    // write your code here
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        input[i] = temp;
    }
    fracKnapsack(input, n, w);

    return 0;
}