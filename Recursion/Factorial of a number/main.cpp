// C++ program to find factorial of given number
#include <iostream>
using namespace std;

int factorial(int n);

// Driver code
int main() {

    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "Factorial of " << n << " = " << factorial(n);

    return 0;
}

// function to find factorial of given number
int factorial(int n) {
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
