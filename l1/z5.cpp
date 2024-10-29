#include <array>
#include <cmath>
#include <iostream>

double compute(double prevI, int n) {
	return 1.0/n - 2024 * prevI;
}

int main() {
	double i = std::log(2025.0/2024.0);

	std::array<double, 21> arr;
	arr[0] = i;

	for(int n = 1; n <= 20; n++) {
		i = compute(i, n);
		arr[n] = i;
		std::cout << "I_" << n << " = " << i << "\n";
	}

	std::cout << "\nPodciągi osobno:\n\n";

	for(int n = 1; n <= 20; n+=2) 
		std::cout << "I_" << n << " = " << arr[n] << "\n";

	std::cout << "\n";

	for(int n = 2; n <= 20; n+=2) 
		std::cout << "I_" << n << " = " << arr[n] << "\n";
}
