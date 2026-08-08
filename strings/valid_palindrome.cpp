#include <iostream>
#include <string>
using namespace std;

class Solution
{
private:
    bool valid(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            return true;
        }

        return false;
    }

    char toLowerCase(char ch)
    {
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9'))
        {
            return ch;
        }
        else
        {
            return ch - 'A' + 'a';
        }
    }

    bool checkPalindrome(string a)
    {
        int s = 0;
        int e = a.length() - 1;

        while (s <= e)
        {
            if (a[s] != a[e])
            {
                return false;
            }

            s++;
            e--;
        }

        return true;
    }

public:
    bool isPalindrome(string s)
    {

        string temp = "";

        // Remove spaces and special characters
        for (int j = 0; j < s.length(); j++)
        {
            if (valid(s[j]))
            {
                temp.push_back(s[j]);
            }
        }

        // Convert to lowercase
        for (int j = 0; j < temp.length(); j++)
        {
            temp[j] = toLowerCase(temp[j]);
        }

        // Check palindrome
        return checkPalindrome(temp);
    }
};

int main()
{

    Solution obj;

    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    if (obj.isPalindrome(s))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
// "A man, a plan, a canal: Panama" test case 1
// "race a car" test case 2