#pragma once
#include <memory>
#include "IScene.h"
#include "StageScene.h"

class GameManager {
public:
	GameManager();
	~GameManager();
	
	// ゲームループを呼び出す
	int Run();

private:
	// シーンを保持するメンバ変数
	std::unique_ptr<IScene> sceneArr_[1];

	// 現在のシーン
	int currentSceneNo_;
	// 前のシーン
	int preSceneNo_;
};