#include <cstddef>
#include <iostream>

void check(double x, double R) {
	double orig = x;
	double y;
	std::size_t i = 0;
	do {
		y = x;
		x = x * (2 - R * x);
		i++;
	} while(x != y && x > 0 && x < 2/R);

	if(x == y) std::cout << "x: " << orig << ", R: " << R << " iterations: " << i << "\n";
}

int main() {
	check(0.2, 5);
	check(0.1, 5);
	check(0.15, 5);
	check(0.12, 5);
	check(0.25, 5);
	check(0.3, 5);
	check(0.00000001, 420);
	check(0.0000001, 420);
	check(0.000001, 420);
	check(0.00001, 420);
	check(0.0001, 420);
	check(0.001, 420);
	check(0.0000000001, 69420);
	check(0.000000001, 69420);
	check(0.00000001, 69420);
	check(0.0000001, 69420);
	check(0.000001, 69420);
	check(0.00001, 69420);
	check(0.000000001, 100000);
	check(0.00000001, 100000);
	check(0.0000001, 100000);
	check(0.000001, 100000);
	check(0.00001, 100000);
	check(0.0001, 100000);
	check(0.001, 100000);
}
