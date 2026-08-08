// You have been given a string 'STR' of words. You need to replace all the spaces between words with "@40"
#include <iostream>
using namespace std;

/*
string replaceSpaces(string &str){
    string temp = "";
    for (int i =0; i<str.length(); i++){
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }else{
            temp.push_back(str[i]);
        }
    }
    return temp;
}
*/

string replaceSpaces(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '@';
            str.insert(i + 1, "40");

            i += 2;
        }
    }
}

/*
int main()
{

    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    string result = replaceSpaces(str);

    cout << "After replacing spaces: " << result << endl;

    return 0;
}
*/


int main()
{

    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    replaceSpaces(str);

    cout << "After replacing spaces: " << str << endl;

    return 0;
}