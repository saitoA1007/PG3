#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

// CSVファイルを読み込む
void LoadMapChipCSV(std::vector<std::vector<int>>& map, std::mutex& mtx, std::atomic<bool>& isLoading) {

	// 2秒待機
	std::this_thread::sleep_for(std::chrono::seconds(2));

	// ファイルを開く
	std::ifstream file("mapChip.csv");
	if (!file.is_open()) {
		// 開けなかった場合もロード終了とする
		isLoading = false;
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

	// 読み込みが終了したら、MutexをロックしてMainデータに書き込む
	{
		std::lock_guard<std::mutex> lock(mtx);
		map = tempMap;
	}

	// データの書き込みが終わったらフラグを無効化
	isLoading = false;
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
	std::atomic<bool> isLoading(true);

	// バックグラウンドループ
	std::thread th([&]() {
		LoadMapChipCSV(mapData, mtx, isLoading);
	});

	// メインループ
	int count = 0;
	while (isLoading.load()) {
		std::cout << "\rロード中" << std::string(count % 4, '.') << "   " << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		count++;
	}

	// スレッドの終了を待機
	if (th.joinable()) {
		th.join();
	}

	// 終了の知らせを描画
	std::cout << "\nマップの読み込み完了\n";
	// 読み込んだマップを描画
	{
		std::lock_guard<std::mutex> lock(mtx);
		DrawMapChip(mapData);
	}
	return 0;
}