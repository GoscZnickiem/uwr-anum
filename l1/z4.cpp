#include <cmath>
#include <cstddef>
#include <iostream>

using T = double;

template<std::size_t N>
constexpr T y = y<N-1> * 35 / 6 + y<N-2>;

template<>
constexpr T y<0> = 1;

template<>
constexpr T y<1> = -1.0 / 6;

template<std::size_t N>
void constexprloop() {
	if constexpr(N > 0) {
		constexprloop<N-1>();
		std::cout << "y_" << N << " = " << y<N> << "\n";
	}
}

int main() {
	constexprloop<50>();
}
