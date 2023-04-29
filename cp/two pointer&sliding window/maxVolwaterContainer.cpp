#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
int maxArea(vector<int>& height) {
    // Write your code here.
    int left=0,right=height.size()-1,maxi=INT_MIN;
    while(left<right){
        maxi=max(maxi,(min(height[left],height[right])*(right-left)));
        if(height[right]>height[left]){
            left++;
        }
        else{
            right--;
        }
    }
    return maxi;
}




int main() {
    int t;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;

        vector<int> v(n);

        for (auto &i : v) {
            cin >> i;
        }

        cout << maxArea(v) << endl;
    }
}