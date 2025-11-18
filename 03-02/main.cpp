#include<iostream>

// 2つ値を比較して、小さい方を返す
template<typename Type>
Type Min(Type a, Type b) {

	if (a >= b) {
		return static_cast<Type>(b);
	} else {
		return static_cast<Type>(a);
	}
}

int main() {
	// int型の比較
	std::cout << "int型の値の比較" << std::endl;
	std::cout << "-> " << Min(1,8) << std::endl << std::endl;

	// float型の比較
	std::cout << "float型の値の比較" << std::endl;
	std::cout << "-> " << Min(10.1f,3.3f) << std::endl << std::endl;

	// double型の比較
	std::cout << "double型の値の比較" << std::endl;
	std::cout << "-> " << Min(5.5, 12.1) << std::endl << std::endl;
	return 0;
}