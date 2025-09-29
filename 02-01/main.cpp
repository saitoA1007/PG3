#include<iostream>
#include<Windows.h>

// 2つの値を比較して値が小さい方を返す
template <typename Type>
Type Min(Type a, Type b) {
	if (a >= b) {
		return static_cast<Type>(b);
	} else {
		return static_cast<Type>(a);
	}
}

int main() {
	// int型の比較する値
	int intNum1 = 1;
	int intNum2 = 4;
	// float型の比較する値
	float floatNum1 = 3.2f;
	float floatNum2 = 7.5f;
	// double型の比較する値
	double doubleNum1 = 2.01;
	double doubleNum2 = 8.02;
	
	// 描画
	std::cout << "Min(int) : " << Min(intNum1, intNum2) << "\n";
	std::cout << "Min(float) : " << Min(floatNum1, floatNum2) << "\n";
	std::cout << "Min(double) : " << Min(doubleNum1, doubleNum2) << "\n";
	return 0;
}