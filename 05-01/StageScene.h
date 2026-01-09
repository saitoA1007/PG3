#pragma once
#include "IScene.h"
#include "Vector2.h"
#include "Player.h"
#include "InputHandler.h"
#include "ICommand.h"

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
	void Update(InPutManager* inputManager) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

private:

	// 入力ハンドル
	InputHandler* inputHandler_ = nullptr;

	// コマンド
	ICommand* iCommand_ = nullptr;

	// プレイヤー
	Player* player_ = nullptr;
};