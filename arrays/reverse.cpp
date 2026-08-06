#include <iostream>
#include <vector>
using namespace std;

void reverse_array(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return;
}

void print_array(const vector<int> &arr){
    for(int i = 0; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[]={11,7,3,12,4,34};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

    cout << "Original array: ";
    print_array(v);

    reverse_array(v);

    cout << "Reversed array: ";
    print_array(v);
    return 0;

}