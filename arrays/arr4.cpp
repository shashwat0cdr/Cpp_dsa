// reverse an array
#include <iostream>
using namespace std;

//  reversing an array
// void printArr(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// void reverse(int arr[], int n)
// {
//     int start = 0;
//     int end = n - 1;
//     while (start <= end)
//     {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }
// int main()
// {
//     int arr[6] = {1, 2, 3, 4, 5, 6};
//     int brr[5] = {5, 6, 7, 78, 8};
//     reverse(arr, 6);
//     reverse(brr, 5);
//     printArr(arr, 6);
//     printArr(brr, 5);
//     return 0;
// }

// swap alternte elements of an array
// void printArr(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// void swapAtlernate(int arr[], int size)
// {
//     for (int i = 0; i < size; i += 2)
//     {
//         if (i + 1 < size)
//         {
//             swap(arr[i], arr[i + 1]);
//         }
//     }
// }
// int main()
// {
//     int even[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int odd[5] = {12, 5, 62, 3, 6};
//     swapAtlernate(even, 8);
//     printArr(even, 8);
//     swapAtlernate(odd, 5);
//     printArr(odd, 5);
//     return 0;
// }

// without using swap function
// void alternate(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i += 2)
//     {
//         int temp = arr[i];
//         arr[i] = arr[i + 1];
//         arr[i + 1] = temp;
//     }
// }
// void printArray(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     alternate(arr, 5);
//     printArray(arr, 5);
//     return 0;
// }

