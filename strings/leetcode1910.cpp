// remove all occurences 
// given 2 strings and part , perform the following operations on s untill all occurences of the substring part are removed

#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part) {

    while (s.length() != 0 && s.find(part) < s.length()) {

        s.erase(s.find(part), part.length());
    }

    return s;
}

int main() {

    string s, part;

    cout << "Enter the main string: ";
    getline(cin, s);

    cout << "Enter the part to remove: ";
    getline(cin, part);

    string result = removeOccurrences(s, part);

    cout << "After removing occurrences: " << result << endl;

    return 0;
} 