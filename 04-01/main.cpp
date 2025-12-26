#include <Novice.h>
#include "InputManager.h"
#include "GameManager.h"

const char kWindowTitle[] = "PG3_LE2A_07_サイトウアオイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// 入力管理クラス
	std::unique_ptr<InPutManager> inputManager = std::make_unique<InPutManager>();

	// ゲーム管理クラス
	std::unique_ptr<GameManager> gameManager = std::make_unique<GameManager>();

	// ゲームの実行
	gameManager->Run(inputManager.get());

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
