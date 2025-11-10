#include<iostream>
#include <time.h>
#include<Windows.h>

// 指定した秒数の演出を実行する
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {

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

// 結果を表示する
void ShowResult(int roll, int userGuess) {
	int result = roll % 2;

	printf("出た目は[% d ]です。\n-> ", roll);

	if (result == userGuess) {
		printf("正解でした\n");
	} else {
		printf("不正解でした\n");
	}
}

int main() {
	// 乱数のシード初期化
	srand((unsigned int)time(NULL));

	int userGuess = 0;
	printf("半(偶数 = 0)か丁(奇数 = 1)を入力してください\n-> ");
	// 入力を受け取る
	scanf_s("%d", &userGuess);

	// 乱数を取得
	int roll = rand() % 6 + 1;

	// サイコロを振る
	DelayReveal(ShowResult, 3000, roll, userGuess);
	return 0;
}
