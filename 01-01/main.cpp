#include <iostream>
#include <list>

/// <summary>
/// 駅名一覧を描画する
/// </summary>
/// <param name="stations">駅名リスト</param>
/// <param name="year">表示する年代</param>
void PrintStationList(const std::list<const char*>& stations, const char* year) {
	// 年代を描画
	std::cout << "Year : " << year << "\n";
	// 駅名を描画
	for (const char* station : stations) {
		std::cout << station << "\n";
	}
	std::cout << "\n";
}

/// <summary>
/// 駅名を追加する関数
/// </summary>
/// <param name="stations">駅名リスト</param>
/// <param name="beforStationName">挿入する前の駅名</param>
/// <param name="addStationName">追加したい駅名</param>
void AddStation(std::list<const char*>& stations, const char* targetStationName, const char* addStationName) {
	for (auto itr = stations.begin(); itr != stations.end(); ++itr) {

		// 文字列を比較する
		if (std::strcmp(*itr, targetStationName) == 0) {
			// 指定した駅の後ろに挿入
			++itr;
			stations.insert(itr, addStationName);
			// 追加が終わったらループを抜ける
			return;
		}
	}
}

int main() {

	// 1970年の駅名リストを作成
	std::list<const char*> stationsList{ "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori", "Tabata", "Komagome",
	"Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro",
	"Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho" };

	// 1970念の駅名一覧を描画
	PrintStationList(stationsList, "1970");

	// 西日暮里駅を追加
	AddStation(stationsList, "Nippori", "Nishi-Nippori");

	// 2019年の駅名一覧を描画
	PrintStationList(stationsList, "2019");

	// 高輪ゲートウェイ駅を追加
	AddStation(stationsList, "Shinagawa", "Takanawa Gateway");

	// 2022年のの駅名一覧を描画
	PrintStationList(stationsList, "2022");
	return 0;
}