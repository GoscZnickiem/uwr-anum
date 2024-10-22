#include <cmath>
#include <iomanip>
#include <iostream>

double originalF(double x, int k) {
	double k2 = std::pow(2, k);
	return k2 * std::sqrt(2 * (1 - std::sqrt(1 - (x/k2) * (x/k2))));
}

double newF(double x, int k) {
	double k2 = std::pow(2, k);
	return x * std::sqrt(2 / (1 + std::sqrt(1 - (x/k2) * (x/k2))));
}

void testCase(double (*f)(double, int)) {
	double x = 2;
	for(int i = 1; i < 50; i++) {
		std::cout << "x_" << i + 1 << ": " << std::fixed << std::setprecision(11) << x << "\n";
		x = f(x, i);
	}
}

int main() {
	testCase(originalF);
	testCase(newF);
}
