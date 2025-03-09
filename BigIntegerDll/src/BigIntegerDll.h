#pragma once
#ifdef BIGINTEGER_DLL_EXPORTS
#define BIGINTEGER_DLL_API __declspec(dllexport)
#else
#define BIGINTEGER_DLL_API __declspec(dllimport)
#endif

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <compare>

class BIGINTEGER_DLL_API BigInteger {
private:
    std::vector<int> digits;
    bool isNegative;
    bool isZero() const;

    void removeLeadingZeros();

    auto compare_digits(const BigInteger& other) const;

    BigInteger inner_add(const BigInteger& other) const;

    BigInteger inner_sub(const BigInteger& other) const;

    BigInteger inner_mul(const BigInteger& other) const;

    std::pair<BigInteger, BigInteger> inner_div(const BigInteger& divisor) const;


public:
    BigInteger(int num = 0) : isNegative(num < 0) {
        num = std::abs(num);
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num > 0);
        removeLeadingZeros();
    };

    auto operator<=>(const BigInteger& other) const;

    bool operator==(const BigInteger& other) const;

    BigInteger operator+(const BigInteger& other) const;

    BigInteger operator-(const BigInteger& other) const;

    BigInteger operator*(const BigInteger& other) const;

    BigInteger operator/(const BigInteger& other) const;

    BigInteger operator%(const BigInteger& other) const;

    friend BIGINTEGER_DLL_API std::ostream& operator<<(std::ostream& os, const BigInteger& num);
};



