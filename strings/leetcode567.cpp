#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26], int b[26]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {

    // If s1 is bigger than s2
    if (s1.length() > s2.length()) {
        return false;
    }

    // Character count of s1
    int count[26] = {0};

    for (int i = 0; i < s1.length(); i++) {
        int index = s1[i] - 'a';
        count[index]++;
    }

    // Window size = length of s1
    int windowSize = s1.length();

    // Character count of current window
    int count2[26] = {0};

    int i = 0;

    // First window
    while (i < windowSize) {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // Check first window
    if (checkEqual(count, count2)) {
        return true;
    }

    // Sliding window
    while (i < s2.length()) {

        // Add new character
        int index = s2[i] - 'a';
        count2[index]++;

        // Remove old character
        index = s2[i - windowSize] - 'a';
        count2[index]--;

        i++;

        // Check current window
        if (checkEqual(count, count2)) {
            return true;
        }
    }

    return false;
}

int main() {

    // Test Case 1
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << "Test Case 1: ";
    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl;


    // Test Case 2
    s1 = "ab";
    s2 = "eidboaoo";

    cout << "Test Case 2: ";
    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl;


    // Test Case 3
    s1 = "abc";
    s2 = "bbbca";

    cout << "Test Case 3: ";
    cout << (checkInclusion(s1, s2) ? "true" : "false") << endl;

    return 0;
}