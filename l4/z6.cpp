#include <cstddef>
#include <cstdlib>
#include <iostream>

void check(double x, double a, double epsilon) {
	double orig = x;
	double y;
	std::size_t i = 0;
	do {
		y = x;
		x = x * (1.5 - a * x);
		i++;
		if(i > 1000) return;
	} while(std::abs(x - y) > epsilon);

	std::cout << "x: " << orig << ", a: " << a << " iterations: " << i << "\n";
}

int main() {
	check(0.1, 5, 0.0001);
	check(0.2, 5, 0.0001);
	check(0.3, 5, 0.0001);
	check(5, 5, 0.0001);
	check(5.0/2, 5, 0.0001);
	check(0.00001, 420, 0.0001);
	check(0.0001, 420, 0.0001);
	check(0.001, 420, 0.0001);
	check(420, 420, 0.0001);
	check(420.0/2, 420, 0.0001);
	check(0.0000001, 69420, 0.0001);
	check(0.000001, 69420, 0.0001);
	check(0.00001, 69420, 0.0001);
	check(69420, 69420, 0.0001);
	check(69420.0/2, 69420, 0.0001);
	check(0.000001, 100000, 0.0001);
	check(0.00001, 100000, 0.0001);
	check(0.0001, 100000, 0.0001);
	check(0.001, 100000, 0.0001);
	check(100000, 100000, 0.0001);
	check(100000.0/2, 100000, 0.0001);
}
