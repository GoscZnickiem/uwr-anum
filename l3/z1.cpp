#include <cmath>
#include <iomanip>
#include <iostream>

using std::numbers::e;
using std::numbers::pi;

double a(double x) {
	return std::pow((std::pow(x, 5) + std::sqrt(std::pow(x,10) + 2024)), -1);
}

double a2(double x) {
	return -2024. / (std::pow(x, 5) - std::sqrt(std::pow(x,10) + 2024));
}

double b(double x) {
	return std::pow(10, 8) * (std::pow(e, x) - std::pow(e, 2 * x));
}

double b2(double x) {
	double k = std::pow(e, x + std::log(10) * 8);
	return k * (1 - k);
}

void compare(double x, double (*f)(double), double (*f2)(double)) {
	std::cout << "x: " << x << " -> " << f(x) << " vs " << f2(x) << "\n";
}

int main() {
	std::cout << std::fixed << std::setprecision(20);

	std::cout << "(a)\n";
	compare(0.00001, a, a2); // Wolfram: 44.988...
	compare(-3000, a, a2);   // Wolfram: 4.164... * 10^-15
	
	std::cout << "(b)\n";
	compare(0.00001, b, b2); // Wolfram:
	compare(-3000, b, b2);   // Wolfram:
}
