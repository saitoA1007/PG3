#include "StageScene.h"
#include <Novice.h>
#include <cmath>

void StageScene::Initialize() {
	// 入力ハンドルを初期化
	inputHandler_ = new InputHandler();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();

	// プレイヤーの初期化
	player_ = new Player();
	player_->Initialize();
}

void StageScene::Update(InPutManager* inputManager) {
	// リセットする
	if (!inputManager->GetPreKeys()[DIK_R] && inputManager->GetKeys()[DIK_R]) {
		sceneNo = static_cast<int>(Scene::STAGE);
	}

	// 入力を受け取る
	iCommand_ = inputHandler_->HandleInput();
	
	// 入力があった場合、実行
	if (iCommand_) {
		iCommand_->Exec(*player_);
	}

	// プレイヤーの更新処理
	player_->Update();
}

void StageScene::Draw() {

	// プレイヤーの描画
	player_->Draw();

	// 現在のシーン名を描画
	Novice::ScreenPrintf(16, 16, "StageScene");
}