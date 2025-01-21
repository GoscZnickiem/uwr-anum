#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>

int sgn(double x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }

std::pair<double, double> bisect(double (*f)(double), double a, double b) {
	double m = (a + b)/2;
	if(sgn(f(m)) == sgn(f(a))) return {m, b};
	return {a, m};
}
std::pair<double, double> bisect(double (*f)(double), std::pair<double, double> interval) {
	return bisect(f, interval.first, interval.second);
}

double find(double (*f)(double), double a, double b) {
	double e = 0.00001;
	int n = std::ceil(std::log2((b - a)/e) - 1);

	std::pair<double, double> interval = {a, b};
	for(int i = 0; i < n; i++) {
		interval = bisect(f, interval);
	}
	return (interval.first + interval.second) / 2;
}

double f(double x) {
	return x * x - std::atan(x + 2);
}

int main() {
	std::cout << find(f, -2, 0) << ", " << find(f, 0, 2) << "\n";
}
