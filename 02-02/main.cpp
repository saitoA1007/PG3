#include <iostream>
#include <Windows.h>

/// <summary>
/// 再帰的な賃金を求める
/// </summary>
/// <param name="hour">時間</param>
/// <returns></returns>
int GetCalcRecursiveWage(int hour) {
	if (hour == 1) {
		return 100;
	}
	return GetCalcRecursiveWage(hour - 1) * 2 - 50;
}

int main() {
	// 通常自給
	const int kNormalWage = 1226;
	// 最初の再帰賃金
	int recursiveWage = 100;

	// 通常賃金の総合
	int totalNormalWage = 0;
	// 再帰的賃金の総合
	int totalRecursiveWage = 0;

	// 時間を計測する
	int hourTimer_ = 0;

	// 再帰的賃金が通常賃金を超えるまで更新
	while (true) {
		hourTimer_++;
		// 通常自給を加算
		totalNormalWage += kNormalWage;
		// 再帰的賃金を取得
		totalRecursiveWage += GetCalcRecursiveWage(hourTimer_);
		// 各時間の賃金を描画
		std::cout << "時間 : " << hourTimer_ << "\n";
		std::cout << "通常賃金 : " << totalNormalWage << "\n";
		std::cout << "再帰的賃金 : " << totalRecursiveWage << "\n\n";

		// 再帰的賃金が通常賃金を越した時ループを終了
		if (totalRecursiveWage > totalNormalWage) {
			std::cout << "\n=================================================\n";
			std::cout << "再帰的賃金の方が儲かる時間 : " << hourTimer_ << "\n";
			break;
		}
	}
	return 0;
}