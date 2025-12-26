#pragma once
#include "IScene.h"
#include "Vector2.h"

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

	// オブジェクトの基本データ
	struct Object {
		Vector2 pos;
		float radius;
		bool isAlive;
	};

	// プレイヤー
	Object player_;

	// 敵
	Object enemy_;

	// 弾
	Object bullet_;
	float bulletSpeed_ = 400.0f;
	bool isBulletShot_ = false;

	// デルタタイム
	static inline const float kDeltaTime = 1.0f / 60.0f;
};