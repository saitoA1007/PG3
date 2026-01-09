#pragma once
#include "Vector2.h"

class Player {
public:
	Player();

	// 初期化
	void Initialize();

	// 更新処理
	void Update();

	// 描画処理
	void Draw();

	// コマンドパターン
	void MoveRight();
	void MoveLeft();

private:

	// 速度
	float speed_ = 5.0f;

	// 位置
	Vector2 pos_ = {};

	// サイズ
	Vector2 size_ = {};
};