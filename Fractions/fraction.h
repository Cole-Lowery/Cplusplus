//
// Created by clowery on 4/22/2025.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <type_traits>
namespace mathlib {
    template<typename T>
    class Fraction {
        static_assert(std::is_arithmetic_v<T>, "Fraction type must be arithmetic");
    private:
        T numerator;
        T denominator;
        static constexpr T findGCD(T a, T b) noexcept {
            while (b != 0) { T temp = b; b = a % b; a = temp; }
            return a;
        }
    public:
        constexpr Fraction() noexcept : numerator(0), denominator(1) {}
        constexpr Fraction(T num, T den) : numerator(num), denominator(den) {
            if (denominator == 0) throw std::invalid_argument("Denominator cannot be zero");
        }
        [[nodiscard]] constexpr Fraction Simplify() const {
            T gcd = findGCD(std::abs(numerator), std::abs(denominator));
            T newNum = numerator / gcd, newDen = denominator / gcd;
            if (denominator < 0) { newNum = -newNum; newDen = -newDen; }
            return Fraction(newNum, newDen);
        }
        [[nodiscard]] constexpr double ToFloat() const noexcept {
            return static_cast<double>(numerator) / denominator;
        }
        [[nodiscard]] constexpr Fraction operator+(const Fraction& other) const {
            return Fraction(numerator * other.denominator + other.numerator * denominator, 
                           denominator * other.denominator).Simplify();
        }
        [[nodiscard]] constexpr Fraction operator-(const Fraction& other) const {
            return Fraction(numerator * other.denominator - other.numerator * denominator, 
                           denominator * other.denominator).Simplify();
        }
        [[nodiscard]] constexpr Fraction operator*(const Fraction& other) const {
            return Fraction(numerator * other.numerator, 
                           denominator * other.denominator).Simplify();
        }
        [[nodiscard]] constexpr Fraction operator/(const Fraction& other) const {
            if (other.numerator == 0) throw std::invalid_argument("Division by zero");
            return Fraction(numerator * other.denominator, 
                           denominator * other.numerator).Simplify();
        }
        constexpr Fraction& operator+=(const Fraction& other) { return *this = *this + other; }
        constexpr Fraction& operator-=(const Fraction& other) { return *this = *this - other; }
        constexpr Fraction& operator*=(const Fraction& other) { return *this = *this * other; }
        constexpr Fraction& operator/=(const Fraction& other) { return *this = *this / other; }
        [[nodiscard]] constexpr bool operator==(const Fraction& other) const noexcept {
            Fraction f1 = this->Simplify(), f2 = other.Simplify();
            return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
        }
        [[nodiscard]] constexpr bool operator!=(const Fraction& other) const noexcept { return !(*this == other); }
        [[nodiscard]] constexpr bool operator<(const Fraction& other) const noexcept {
            return numerator * other.denominator < other.numerator * denominator;
        }
        [[nodiscard]] constexpr bool operator>(const Fraction& other) const noexcept { return other < *this; }
        [[nodiscard]] constexpr bool operator<=(const Fraction& other) const noexcept { return !(other < *this); }
        [[nodiscard]] constexpr bool operator>=(const Fraction& other) const noexcept { return !(*this < other); }
        [[nodiscard]] constexpr T getNumerator() const noexcept { return numerator; }
        [[nodiscard]] constexpr T getDenominator() const noexcept { return denominator; }
        friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
            return os << f.numerator << "/" << f.denominator;
        }
        friend std::istream& operator>>(std::istream& is, Fraction& f) {
            is >> f.numerator >> f.denominator;
            if (f.denominator == 0) throw std::invalid_argument("Denominator cannot be zero");
            return is;
        }
    };
}
#endif //FRACTION_H