
// memoization is top down approach which is used by recursion .........It is not a Dynamic Programming:it is mainly iterative way to solve.

#include <iostream>
using namespace std;
int helperFibbo(int n, int *memoArray)
{
    // base case
    if (n <= 1)
    {

        return n;
    }
    // check the value is present or not..
    if (memoArray[n] != -1)
    {
        // return the value is stored in array.that's mean it's is used before
        return memoArray[n];
    }
    int a = helperFibbo(n - 1, memoArray);
    int b = helperFibbo(n - 2, memoArray);
    // stored the value which is occured the first time
    memoArray[n] = a + b;

    return memoArray[n];
}
int fibbo_memo(int n)
{
    int *memoArray = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        // initialize the all value -1 as a empty marked
        memoArray[i] = -1;
    }
    return helperFibbo(n, memoArray);
}
int main()
{
    int n;
    cout << "enter the number:";
    cin >> n;
    cout << "the fibbo numis :" << fibbo_memo(n);
}
