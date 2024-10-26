#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::vector<float> numbers;

	for(int i = 0; i < 1 << 4; i++) {
		for(float j = 0.5f; j <= 2; j *= 2) {
			for(int k = -1; k < 2; k += 2) {
				float num = k * static_cast<float>((1 << 4) + i) * j / (1 << 5);
				auto pos = std::lower_bound(numbers.begin(), numbers.end(), num);
				numbers.insert(pos, num);
			}
		}
	}

	for(auto i : numbers) {
		std::cout << i << "\n";
	}
	std::cout << numbers.size() << "\n";
}
