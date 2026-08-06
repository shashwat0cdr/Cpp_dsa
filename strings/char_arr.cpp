#include <iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}

bool checkPalindrome(char a[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (a[s] != a[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

int main()
{
    char name[20];

    cout << "Enter your name: ";
    cin >> name;
    cout << "Your name is: " << name << endl;

    cout << "Length: " << getLength(name) << endl;
    int len = getLength(name);

    reverse(name, len);
    cout << "reverse name: " << name << endl;
   
    cout << "palindrome or not: " << checkPalindrome(name, len) << endl;
   
   
    return 0;
}