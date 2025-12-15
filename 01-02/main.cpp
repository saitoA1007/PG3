#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

/// <summary>
/// テキストファイルをロード、カンマ区切りでstd::vectorに保存する
/// </summary>
/// <param name="fileName">ファイル名</param>
/// <param name="names">名前が保存されたコンテナ</param>
void LoadTxtFile(const std::string& fileName, std::vector<std::string>& names) {
	// ファイルを開く
	std::ifstream file(fileName);

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string name;
		// カンマ区切りでアドレスを保存していく
		while (std::getline(ss, name, ',')) {
			if (!name.empty()) {
				names.push_back(name);
			}
		}
	}
}

/// <summary>
/// 学年番号を取得する
/// </summary>
/// <param name="name"></param>
/// <returns></returns>
int ExtractYearNumber(const std::string& name) {
	// kとgの位置を取得
	size_t kPos = name.find('k');
	size_t gPos = name.find('g');

	// kとgの間の数字を取得
	std::string numStr = name.substr(kPos + 1, gPos - (kPos + 1));
	return std::stoi(numStr);
}

/// <summary>
/// 学籍番号を取得する
/// </summary>
/// <param name="name">名前</param>
/// <returns></returns>
int ExtractStudentIdNumber(const std::string& name) {
	// gの位置のインデックスを取得
	size_t strIndex = name.find("g");

	// gの次の位置から学籍番号を取得
	std::string numStr;
	for (size_t i = strIndex + 1; i < name.size(); ++i) {
		if (std::isdigit(name[i])) {
			numStr += name[i];
		} else {
			break;
		}
	}

	// 数字に変換
	return std::stoi(numStr);
}

/// <summary>
/// 学年と学籍番号を元にソートをおこなう
/// </summary>
/// <param name="names">名前が保存されたコンテナ</param>
void SortByStudentId(std::vector<std::string>& names) {
	std::sort(names.begin(), names.end(),
		[](const std::string& a, const std::string& b) {
			int yearA = ExtractYearNumber(a);
			int yearB = ExtractYearNumber(b);

			//学年でで比較
			if (yearA != yearB) {
				return yearA < yearB; 
			}
			return ExtractStudentIdNumber(a) < ExtractStudentIdNumber(b);
		});
}

int main() {

	// 名前を保存する変数
	std::vector<std::string> names;

	// テキストファイルから取得する
	LoadTxtFile("PG3_2025_01_02.txt", names);

	// 学籍番号でソートをおこなう
	SortByStudentId(names);

	// 描画
	for (const std::string name : names) {
		std::cout << name << "\n";
	}
	return 0;
}