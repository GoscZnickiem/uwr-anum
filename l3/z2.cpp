#include <cmath>
#include <iostream>

std::pair<double, double> zeros(double a, double b, double c){
	double deltasqr = std::sqrt(b * b - 4 * a * c);

    return { (-b - deltasqr)/(2 * a), (-b + deltasqr)/(2 * a) };
}

std::pair<double,double> zeros2(double a, double b, double c){
	double deltasqr = std::sqrt(b * b - 4 * a * c);
	double x1 = (-b + (b >= 0 ? -1 : 1) * deltasqr) / (2 * a);
	return { x1, c / x1 / a };
}

void compare(double a, double b, double c){
    std::cout <<"a = " << a << ", b = " << b << ", c = " << c << ":" << '\n';
    std::cout << "x1 = " << zeros(a,b,c).first << ", x2 = " << zeros(a,b,c).second << '\n';
    std::cout << "x1 = " << zeros2(a,b,c).first << ", x2 = " << zeros2(a,b,c).second << '\n';
}

int main(){
    compare(1,10000000000,1);
	std::cout << "\n";
    compare(1,-10000000000,1);
}
