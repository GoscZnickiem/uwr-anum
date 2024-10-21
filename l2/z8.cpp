#include <cmath>
#include <iostream>

template<typename T>
T f(T x) {
	return 1518 * (2 * x - std::sin(2 * x)) / (x*x*x);
}

template<typename T>
T f2(T x) {
	return 1518 * (4.0/3 - 32.0/120 * x * x + 128.0/5040 * x * x * x * x);
}

template<typename T>
void test(T (*f)(T), const std::string& name) {
	std::cout << name << ":\n";
	for(int i = 1; i <= 20; i++) {
		T x = std::pow(10, -i);
		std::cout << "f(10^-" << i << ") = " << f(x) << "\n";
	}
}

int main() {
	test<float>(f, "Single");
	test<float>(f2, "Single, new f");
	test<double>(f, "Double");
	test<double>(f2, "Double, new f");
}
