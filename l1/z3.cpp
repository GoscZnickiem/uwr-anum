#include <cmath>
#include <iostream>

template<typename T>
T f(T x) {
	return 1518 * (2 * x - std::sin(2 * x)) / (x*x*x);
}

template<typename T>
void test(const std::string& name) {
	std::cout << name << ":\n";

	for(int i = 11; i <= 20; i++) {
		T x = std::pow(10, -i);
		std::cout << "f(10^-" << i << ") = " << f(x) << "\n";
	}
}

int main() {
	test<float>("Single");
	test<double>("Double");
	test<long double>("Quadruple");
}
