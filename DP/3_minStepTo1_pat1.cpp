#include <iostream>
#include <climits>
using namespace std;
int helperCount(int n, int count)
{
    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if (n <= 1)
    {
        return 0;
    }
    if (n % 3 == 0)
    {
        ans1 = helperCount(n / 3, count + 1);
    }
    if (n % 2 == 0)
    {
        ans2 = helperCount(n / 2, count + 1);
    }
    ans3 = helperCount(n - 1, count + 1);
    return min(ans1, min(ans2, ans3)) + 1;
}
int countMinStepsToOne(int n)
{
    // Write your code here
    int count = 0;
    return helperCount(n, count);
}
int main()
{
    int n;
    cout << "enter the number:";
    cin >> n;
    cout << countMinStepsToOne(n);
}