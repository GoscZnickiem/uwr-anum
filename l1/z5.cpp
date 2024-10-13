#include <cmath>
#include <iostream>

double compute(double prevI, int n) {
	return 1.0/n - 2024 * prevI;
}

int main() {
	double i = std::log(2025.0/2024.0);
	for(int n = 1; n <= 20; n++) {
		i = compute(i, n);
		std::cout << "I_" << n << " = " << i << "\n";
	}
}
