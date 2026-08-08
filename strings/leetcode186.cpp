#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void reverseArray(vector<char> &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

public:
    void reverseWords(vector<char> &s)
    {

        int n = s.size();

        // Step 1: Reverse the complete array
        reverseArray(s, 0, n - 1);

        // Step 2: Reverse each individual word
        int start = 0;

        for (int i = 0; i <= n; i++)
        {

            if (i == n || s[i] == ' ')
            {

                reverseArray(s, start, i - 1);

                start = i + 1;
            }
        }
    }
};

int main()
{

    Solution obj;

    vector<char> s = {
        't', 'h', 'e', ' ',
        's', 'k', 'y', ' ',
        'i', 's', ' ',
        'b', 'l', 'u', 'e'};

    obj.reverseWords(s);

    cout << "Output: ";

    for (char ch : s)
    {
        cout << ch;
    }

    cout << endl;

    return 0;
}