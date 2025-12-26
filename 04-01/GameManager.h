#pragma once
#include <memory>
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

class GameManager {
public:
	GameManager();
	~GameManager();
	
	// ゲームループを呼び出す
	int Run(InPutManager* inputManager);

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[3];

	// 現在のシーン
	int currentSceneNo_;
	// 前のシーン
	int preSceneNo_;
};