#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// CSVファイルを読み込む
void LoadMapChipCSV(std::vector<std::vector<int>>& map, std::mutex& mtx) {

	// 2秒待機
	std::this_thread::sleep_for(std::chrono::seconds(2));

	// ファイルを開く
	std::ifstream file("mapChip.csv");
	if (!file.is_open()) {
		return;
	}

	// マップを読み込む
	std::vector<std::vector<int>> tempMap;
	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string cell;
		std::vector<int> row;

		while (std::getline(ss, cell, ',')) {
			row.push_back(std::stoi(cell));
		}
		tempMap.push_back(row);
	}

	// 読み込みが終了したら、MutexをロックしてMaineデータに書き込む
	{
		std::lock_guard<std::mutex> lock(mtx);
		map = tempMap;
	}
}

// マップチップ描画
void DrawMapChip(std::vector<std::vector<int>> map) {
	for (const auto& row : map) {
		for (int num : row) {
			std::cout << num << " ";
		}
		std::cout << "\n";
	}
}

int main() {
	std::vector<std::vector<int>> mapData;
	std::mutex mtx;
	bool isLoading = true;

	// バックグラウンドループ
	std::thread th([&]() {
		// マップを読み込む
		LoadMapChipCSV(mapData, mtx);
		// フラグを更新
		isLoading = false;
	});

	// メインループ
	int count = 0;
	while (true) {
		std::cout << "\rロード中" << std::string(count % 4, '.') << "   " << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		count++;

		// ループから抜ける
		if (!isLoading) {
			break;
		}
	}

	// 終了の知らせを描画
	std::cout << "\nマップの読み込み完了\n";
	// 読み込んだマップを描画
	DrawMapChip(mapData);
	// スレッドの終了
	th.join();
	return 0;
}