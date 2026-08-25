// object or simple macros
// #include <iostream>
// using namespace std;
// #define PI 3.14159
// int main()
// {
//     int r = 5;
//    // double pi = 3.14159;
//     double area = PI * r * r;
//     cout << "area is: " << area << endl;
//     return 0;
// }  

// function like macro 
// #include <iostream>
// using namespace std;
// #define SQUARE(x) (x * x)
// int main()
// {
//     int n = 7;
//     int result = SQUARE(n); // Expands to: (n * n)
//     cout << "Square of " << n << " is " << result;
//     return 0;
// }

// pre defined macros
// #include <iostream>
// using namespace std;
// int main()
// {
//     // Display the current line number and the source file
//     // name
//     cout << "This is line " << __LINE__ << " in file "
//          << __FILE__ << "\n";
//     // Display the compilation date
//     cout << "Compiled on " << __DATE__;
//     return 0;
// }