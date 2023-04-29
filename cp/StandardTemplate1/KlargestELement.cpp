#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>
using namespace std;
vector<int> kLargest(int arr[], int n, int k)
{
    // Write your code here
    priority_queue<int> heap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        heap.push(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        ans.push_back(heap.top());
        heap.pop();
    }
    return ans;
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k;

    vector<int> output = kLargest(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    delete[] input;
}