#include <cmath>
#include <iostream>

double f(double x) {
	return 8096.0 * (std::sqrt(std::pow(x, 13) + 4) - 2) / std::pow(x, 14);
}

double f2(double x) {
	return 8096.0 * (1.0 / (x * (std::sqrt(std::pow(x, 13) + 4) + 2)));
}

int main() {
	double x = 0.001;
	std::cout << f(x) << " " << f2(x) << "\n";
}
