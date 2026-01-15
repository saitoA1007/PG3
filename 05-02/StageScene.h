#pragma once
#include <list>
#include <vector>
#include "IScene.h"
#include "StageSceneInputHandler.h"
#include "SelectorCommand.h"
#include "Selector.h"
#include "Unit.h"

class StageScene : public IScene {
public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="inputManager"></param>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

private:

	// ステージの入力処理
	StageSceneInputHandler* inputHandler_ = nullptr;
	IStageSceneCommand* command_ = nullptr;
	// コマンド履歴
	std::list<IStageSceneCommand*> commandHistory_;
	std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

	// セクタ
	Selector* selector_;

	// ユニット達
	std::vector<Unit*> units_;
};