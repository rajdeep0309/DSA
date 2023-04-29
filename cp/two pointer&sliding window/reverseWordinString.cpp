#include <iostream>
#include <string>
#include <ios>
#include <limits>
using namespace std;
string reverseString(string str)
{
    // Write your code here.

    // if the string is " " then return ""
    if (str == "" || str == " ")
    {
        return "";
    }

    string ans;

    int start = str.length() - 1;

    while (start >= 0)
    {

        // Skip multiple spaces
        if (str[start] == ' ')
        {
            start--;
        }
        else
        {

            // Add space between words
            if (ans.length() > 0)
            {
                ans.push_back(' ');
            }

            int j = start;

            while (j >= 0 && str[j] != ' ')
            {
                j--;
            }

            // add current word to ans
            ans.append(str.substr(j + 1, start - j));
            start = j;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (t--)
    {
        string str;

        getline(cin, str);

        if (str[str.size() - 1] == 13)
            str.erase(str.size() - 1);

        cout << reverseString(str) << '\n';
    }
}