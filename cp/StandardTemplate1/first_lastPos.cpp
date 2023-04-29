/*
First and last position of element in the sorted array
Send Feedback
You are given a sorted array ARR consisting of N integers and an integer X. You need to find the first and last position of occurrence of X in the array.
Note:
1. The array follows 0-based indexing, so you need to return 0-based indices.
2. If X is not present in the array, return “-1 -1”.
3. If X is only present once in the array, the first and last position of its occurrence will be the same.
Follow Up:
Try to solve the problem in O(log(N)) time complexity.
Input Format:
The first line contains the integer N, denoting the size of the sorted array.

The second line contains N space-separated integers denoting the array elements.

The third line contains the value X, whose first and last position of occurrence you need to find.
Output Format:
The only line of output should contain two space-separated integers, where the first and second integer will be the first and the last position of occurrence of X, respectively, in the array.
Note:
Just implement the given function. You do not need to print anything. It has already been taken care of.
Constraints:
1 <= N <= 10^4
-10^9 <= ARR[i] <= 10^9
-10^9 <= X <= 10^9

Time Limit: 1sec
Sample Input 1:
5
-10 -5 -5 -5 2
-5
Sample Output 1:
1 3
Explanation for Sample Input 1:
The given array’s 0-based indexing is as follows:
-10    -5    -5    -5     2
 ↓      ↓     ↓     ↓     ↓
 0      1     2     3     4

So, the first occurrence of -5 is at index 1, and the last occurrence of -5 is at index 3.
Sample Input 2:
4
1 2 3 4
-1
Sample Output 2:
-1 -1
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
    // Write your code here.
    pair<int, int> ans;
    ans.first = -1;
    ans.second = -1;
    int firstIndex = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int endIndex = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    if (firstIndex != 0)
    {
        ans.first = firstIndex;
    }
    ans.second = endIndex;
    return ans;
}

int main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // freopen("./Testcases/large/in/input11.txt", "r", stdin);
    // freopen("./Testcases/large/out/output11.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int X;
    cin >> X;

    pair<int, int> sol = findFirstLastPosition(arr, N, X);
    cout << sol.first << " " << sol.second << endl;
}