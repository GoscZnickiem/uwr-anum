#include <iomanip>
#include <iostream>
#include <numbers>

int main() {
	double pi = 0;

	for(unsigned long long i = 0; i < 2000000; i++) {
		pi += (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
	}

	pi *= 4;
	std::cout << std::fixed << std::setprecision(11) << pi << "\n" << std::fixed << std::setprecision(10) << std::numbers::pi << "\n";
}
