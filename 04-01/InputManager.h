#pragma once
#include "Vector2.h"

// 入力を管理するクラス
class InPutManager {
public:

	/// <summary>
	/// 入力の更新処理
	/// </summary>
	void Update();

	// 前フレームの入力ゲッター
	char* GetPreKeys() { return preKeys_; }

	// 現フレームの入力ゲッター
	char* GetKeys() { return keys_; }

private:
	// キーボード
	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };
};

