#include <cmath>
#include <cstdlib>
#include <iostream>
#include <utility>

int sgn(double x) {
	return x > 0 ? 1 : x < 0 ? -1 : 0;
}

std::pair<double, double> bisect(double (*f)(double), double a, double b) {
	double m = (a + b)/2;
	if(sgn(f(m)) == sgn(f(a))) return {m, b};
	return {a, m};
}
std::pair<double, double> bisect(double (*f)(double), std::pair<double, double> interval) {
	return bisect(f, interval.first, interval.second);
}

double f(double x) {
	return x - 0.49;
}

int main() {
	std::pair<double, double> interval = {0, 1};
	double alfa = 0.49;

	for(int n = 1; n <= 5; n++) {
		interval = bisect(f, interval);
		double m = (interval.first + interval.second) / 2;
		double en = std::abs(alfa - m);
		double estimate = std::pow(2.0, -n-1);
		std::cout << "Krok " << n << ": m_n+1 = " << m << ", |e_n| = " << en << ", oszacowanie = " << estimate << ", różnica = " << estimate - en << "\n";
	}
}
