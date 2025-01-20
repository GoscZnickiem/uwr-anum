#include <cmath>
#include <iomanip>
#include <iostream>
#include <numbers>
#include <vector>

using uint = unsigned int;

template<typename T>
void romper(T (*f)(T), T a, T b, uint x) {
	std::vector<std::vector<T>> tab;
	tab.resize(21);

	tab[0].resize(21);
	for(uint j = 0; j <= 20; j++) {
		const uint n = 1u << j;
		const T h = (b - a) / n;
		tab[0][j] = f(a) / 2 * h + f(b) / 2 * h;
		for(uint k = 1; k <= n - 1; k++) {
			tab[0][j] += h * f(a + k * h);
		}
	}

	for(uint i = 1; i <= 20; i++) {
		tab[i].resize(21 - i);
		const T four = static_cast<T>(1ull << (2 * i));
		for(uint j = 0; j <= 20 - i; j++) {
			tab[i][j] = (four * tab[i-1][j+1] - tab[i-1][j]) / (four - 1);
		}
	}

	for(auto v : tab[x]) std::cout << v << "\n";
}

using T = double;
constexpr auto pi = std::numbers::pi;

int main() {
	std::cout << std::fixed << std::setprecision(20);
	auto a = [](T x){
		return 2025 * x * x * x * x * x * x * x - 2005 * x * x * x * x * x * x - 2016 * x * x;
	};
	auto b = [](T x){
		return 1 / (1 + 25 * x * x);
	};
	auto c = [](T x){
		return std::cos(3 * x + pi / 4);
	};
	romper<T>(a, -5, 3, 20);
	std::cout << "\n";
	romper<T>(b, -1, 1, 20);
	std::cout << "\n";
	romper<T>(c, -3 * pi, pi / 6, 19);
}
