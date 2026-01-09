#include "InputManager.h"
#include <Novice.h>

void InPutManager::Update() {
	// キーボード入力を同期させる
	memcpy(preKeys_, keys_, 256);
	// キーボード入力
	Novice::GetHitKeyStateAll(keys_);
}