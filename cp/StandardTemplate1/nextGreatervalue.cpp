#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> input)
{
    // Write your code here
    int size = input.size();
    stack<int> st;
    vector<int> ans(size, -1);

    for (int i = size - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            st.push(input[i]);
        }
        else
        {
            while (!st.empty() && input[i] >= st.top())
            {
                st.pop();
            }
            if (st.empty())
            {
                st.push(input[i]);
            }
            else
            {
                ans[i] = st.top();
                st.push(input[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int size, temp;
    cin >> size;

    vector<int> input;

    for (int i = 0; i < size; i++)
    {
        cin >> temp;
        input.push_back(temp);
    }

    vector<int> output = nextGreaterElement(input);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}