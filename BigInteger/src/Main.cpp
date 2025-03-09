#include <iostream>
#include "BigIntegerDll.h"

static BigInteger fibonacci(int n) {
    if (n == 0) return BigInteger(0);
    if (n == 1) return BigInteger(1);
    BigInteger a(0);
    BigInteger b(1);
    BigInteger result;
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

static BigInteger factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Factorial is not defined for negative numbers.");
    }
    BigInteger result(1);
    for (int i = 2; i <= n; ++i) {
        result = result * BigInteger(i);
    }
    return result;
}

int main() {
    BigInteger num1(987654321);
    BigInteger num2(123456789);

    std::cout << "num1: " << num1 << std::endl;
    std::cout << "num2: " << num2 << std::endl;

    BigInteger sum = num1 + num2;
    std::cout << "Sum1: " << sum << std::endl;

    BigInteger diff = num1 - num2;
    std::cout << "Difference: " << diff << std::endl;

    BigInteger cheng = num1 * num2;
    std::cout << "Cheng: " << cheng << std::endl;

    BigInteger chu = num1 / num2;
    std::cout << "Chu: " << chu << std::endl;

    BigInteger quyu = num1 % num2;
    std::cout << "Quyu: " << quyu << std::endl;

    int n = 100;
    BigInteger fib = fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << fib << std::endl;

    int x = 20;
    BigInteger fact = factorial(x);
    std::cout << x << "! = " << fact << std::endl;

    std::cin.get();

    return 0;
}