#include<iostream>
using namespace std;

void selection_sort(int arr[], int n){
    for (int i=0; i<n; i++){
        int min_index = i;
        for (int j = i+1; j<n; j++){
            if (arr[j] <arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main(){
    int arr[] = {5,3,2,9,6,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    cout << "Sorted array: ";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}