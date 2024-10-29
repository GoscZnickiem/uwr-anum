#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <numbers>

using std::numbers::pi;

double sin(double x) {
	x -= pi;
	double x3 = x * x * x;
	double x5 = x3 * x * x;
	double x7 = x5 * x * x;
	double x9 = x7 * x * x;

	return -(x - 1./6 * x3 + 1./120 * x5 - 1./5040 * x7 + 1./362880 * x9);
}

std::string space(std::size_t n) {
	return std::string(n, ' ');
}

void compare(double x) {
	std::cout << x << space(4) << sin(x) << space(4) << std::sin(x) << "\n";
}

int main() {
	const std::size_t p = 20;
	std::cout << "  x values" << space(p - 2) << "my sin" << space(p) << "std::sin\n" << std::fixed << std::setprecision(p);
	compare(0);
	compare(1);
	compare(2);
	compare(3);
	compare(4);
	compare(5);
	compare(6);
	compare(pi/2);
	compare(pi);
	compare(3*pi/4);
	compare(2*pi);
}
