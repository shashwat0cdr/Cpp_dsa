#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans)
{
    // base case

    if (index >= str.length()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(str, output, index + 1, ans);

    //include
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
    output.pop_back(); // backtrack
}

vector<string> subsequences(string str)
{

    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans = subsequences(str);
    for (auto i : ans)
    {
        cout << i << endl;
    }
}