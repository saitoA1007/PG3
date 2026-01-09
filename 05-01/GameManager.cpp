#include "GameManager.h"
#include <Novice.h>

GameManager::GameManager() {
	// 各シーンの配列
	sceneArr_[static_cast<size_t>(Scene::STAGE)] = std::make_unique<StageScene>();

	// 現在のシーンを設定
	currentSceneNo_ = static_cast<int>(Scene::STAGE);
	sceneArr_[currentSceneNo_]->Initialize();
}

GameManager::~GameManager() {}

int GameManager::Run(InPutManager* inputManager) {
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// 入力処理の更新処理
		inputManager->Update();

		// シーンのチェック
		preSceneNo_ = currentSceneNo_;
		currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

		// シーンの変更を確認
		if (preSceneNo_ != currentSceneNo_) {
			sceneArr_[currentSceneNo_]->Initialize();
		}

		// 更新処理
		sceneArr_[currentSceneNo_]->Update(inputManager);

		// 描画処理
		sceneArr_[currentSceneNo_]->Draw();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (inputManager->GetPreKeys()[DIK_ESCAPE] == 0 && inputManager->GetKeys()[DIK_ESCAPE] != 0) {
			break;
		}
	}
	return 0;
}