#pragma once
#include "IScene.h"

class ClearScene : public IScene {
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
};