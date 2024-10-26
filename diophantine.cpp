#include <iostream>
#include <tuple>

// Function to perform the Extended Euclidean Algorithm
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Function to solve ax + by = c
bool solve_diophantine(long long a, long long b, long long c, long long &x0, long long &y0, long long &g) {
    g = extended_gcd(abs(a), abs(b), x0, y0);
    if (c % g != 0) {
        return false; // No solution exists
    }

    // Scale the solution (x0, y0) by c / g
    x0 *= c / g;
    y0 *= c / g;

    // Adjust signs based on the original values of a and b
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

// Function to find all solutions
std::tuple<long long, long long> get_solution(long long a, long long b, long long x0, long long y0, long long g, long long k) {
    long long x = x0 + k * (b / g);
    long long y = y0 - k * (a / g);
    return std::make_tuple(x, y);
}

int main() {
    long long a = 15, b = 25, c = 35;
    long long x0, y0, g;

    if (solve_diophantine(a, b, c, x0, y0, g)) {
        std::cout << "One solution to " << a << "x + " << b << "y = " << c << " is x = " << x0 << ", y = " << y0 << "\n";

        // Generating other solutions by varying k
        long long k = 1; // You can change k to generate different solutions
        auto [x, y] = get_solution(a, b, x0, y0, g, k);
        std::cout << "Another solution is x = " << x << ", y = " << y << "\n";
    } else {
        std::cout << "No solution exists for " << a << "x + " << b << "y = " << c << "\n";
    }

    return 0;
}
