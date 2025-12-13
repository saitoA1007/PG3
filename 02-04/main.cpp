#include <iostream>
#include <time.h>
#include <Windows.h>
#include <functional>

// サイコロを振る演出
void DelayReveal(std::function<void(int, int)> fn, unsigned int delayMs, int roll, int userGuess) {

	// 待つ時間(秒)を取得する
	int waitTime = delayMs / 1000;

	// 演出を実行する
	for (int i = 0; i < waitTime; ++i) {
		printf("...\n");
		Sleep(1000);
	}

	// 結果を呼び出す
	fn(roll, userGuess);
}

int main() {
	// 乱数のシード初期化
	srand((unsigned int)time(NULL));

	// 入力を受け取る
	printf("半(偶数 = 0)か丁(奇数 = 1)を入力してください\n-> ");
	int userGuess = 0;
	scanf_s("%d", &userGuess);

	// 乱数を取得
	int roll = rand() % 6 + 1;

	// 結果を表示する関数
	auto ShowResult = [](int roll, int userGuess) {
		int result = roll % 2;

		printf("出た目は[% d ]です。\n-> ", roll);

		if (result == userGuess) {
			printf("正解でした");
		} else {
			printf("不正解でした");
		}
		};

	// サイコロを振る
	DelayReveal(ShowResult, 3000, roll, userGuess);
	return 0;
}
