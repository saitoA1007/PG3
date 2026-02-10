#include <iostream>

template <typename T1, typename T2>
class Comparator {
public:
	// 2つ値を比較して、小さい方を返す
	auto Min(T1 a, T2 b) {
		return (a < b) ? a : b;
	}
};

int main() {
	// int型同士の比較
	Comparator<int, int> compInt;
	std::cout << "[int - int] Min(1, 8): "
		<< compInt.Min(1, 8) << std::endl;

	// float型同士の比較
	Comparator<float, float> compFloat;
	std::cout << "[float - float] Min(10.1f, 3.3f): "
		<< compFloat.Min(10.1f, 3.3f) << std::endl;

	// double同士の比較
	Comparator<double, double> compDouble;
	std::cout << "[double - double] Min(5.5, 12.1): "
		<< compDouble.Min(5.5, 12.1) << std::endl;

	// intとfloat型の比較
	Comparator<int, float> compIntFloat;
	std::cout << "[int - float] Min(5, 3.2f): "
		<< compIntFloat.Min(5, 3.2f) << std::endl;

	// intとdouble型の比較
	Comparator<int, double> compIntDouble;
	std::cout << "[int - double] Min(10, 9.9): "
		<< compIntDouble.Min(10, 9.9) << std::endl;

	// floatとdouble型の比較
	Comparator<float, double> compFloatDouble;
	std::cout << "[float - double] Min(3.3f, 2.5): "
		<< compFloatDouble.Min(3.3f, 2.5) << std::endl;
	return 0;
}