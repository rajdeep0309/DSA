#include <iostream>
using namespace std;
void fibboDP(int n, int *ans)
{
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return;
}
int main()
{
    int n;
    cout << "enter the num:";
    cin >> n;
    int *ans = new int[n + 1];

    fibboDP(n, ans);
    cout << ans[n] << endl;
}