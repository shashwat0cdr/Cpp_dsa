#include<iostream>
using namespace std;

void reverseString(string &str, int i, int j){

    // base case
    if(i>j){
        return; 
    }

    // swapping
    swap(str[i], str[j]);
    i++;
    j--;
    
    // recursive call
    reverseString(str, i, j);

}

int main(){

    string str = "Shashwat Gujrati";
    reverseString(str, 0, str.length() - 1);
    cout << str << endl;
    return 0;
    
}