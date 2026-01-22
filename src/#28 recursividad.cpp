#include <iostream>
#include <string>

using namespace std;

// Recursive

// Sumatoria
int sum (int n){
    if (n <= 0){
        return 0;
    }
    return sum (n - 1) + n;
}

// Factorial
int factorial (int n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

// Máximo común divisor
int gcd(int first, int second){
    if(second == 0){
        return first;
    }
    return gcd(second, first % second);
}

// Serie fibonacci
long fib(long n){
    if (n == 0){
        return 0;
    }

    if (n == 1){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

// Revertir una cadena //hola
string reverse(string str){
    if (str.length() <= 1)
        return str;

    return reverse (str.substr (1, str.length() - 1)) + str.substr (0, 1);
}


int main() {
    cout << "Sumatoria de 5: " << sum(5) << endl;
    cout << "Factorial de 5: " << factorial(5) << endl;
    cout << "MCD de 16 y 24: " << gcd(16,14) << endl;
    cout << "Fibonnaci 6: " << fib(6) << endl;

    return 0;
}