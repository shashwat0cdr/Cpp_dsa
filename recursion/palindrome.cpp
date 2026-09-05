#include<iostream>
using namespace std;

bool isPalindrome(string str, int s , int e){

    // base case
    if (s >= e){
        return true;
    }

    if(str[s] != str[e]){
        return false;
    }
    else{
        // recursive call
        return isPalindrome(str, s + 1, e - 1);
    }
    
}

int main(){

    string name = "racecar";
    cout << endl;


    bool ans = isPalindrome(name, 0, name.length() - 1);
    if(ans){
        cout << "The string is a palindrome" << endl;
    }
    else{
        cout << "The string is not a palindrome" << endl;
    }

    return 0;

}