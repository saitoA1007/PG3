#include "StageSceneInputHandler.h"
#include "SelectorCommand.h"
#include "Selector.h"
#include "Unit.h"
#include <Novice.h>

StageSceneInputHandler::StageSceneInputHandler() {

}

void StageSceneInputHandler::UpdateKeyState() {
	// キーボード入力を同期させる
	memcpy(preKeys_, keys_, 256);
	// キーボード入力
	Novice::GetHitKeyStateAll(keys_);
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
	int x = selector->GetMapX();
	int y = selector->GetMapY();
	bool moved = false;

	// セレクタを操作
	if ((keys_[DIK_UP] && !preKeys_[DIK_UP]) || (keys_[DIK_W] && !preKeys_[DIK_W])) {
		y--;
		moved = true;
	}
	if ((keys_[DIK_DOWN] && !preKeys_[DIK_DOWN]) || (keys_[DIK_S] && !preKeys_[DIK_S])) {
		y++;
		moved = true;
	}
	if ((keys_[DIK_LEFT] && !preKeys_[DIK_LEFT]) || (keys_[DIK_A] && !preKeys_[DIK_A])) {
		x--;
		moved = true;
	}
	if ((keys_[DIK_RIGHT] && !preKeys_[DIK_RIGHT]) || (keys_[DIK_D] && !preKeys_[DIK_D])) {
		x++;
		moved = true;
	}

	// セレクタを移動
	if (moved) {
		return new SelectMoveCommand(selector, x, y);
	}

	// スペースキーでユニットを選択
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		return new SelectUnitCommand(selector);
	}

	return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
	if (!unit) return nullptr;

	int x = unit->GetMapX();
	int y = unit->GetMapY();
	bool moved = false;

	// ユニットを操作
	if (keys_[DIK_UP] && !preKeys_[DIK_UP] || (keys_[DIK_W] && !preKeys_[DIK_W])) {
		y--;
		moved = true;
	}
	if ((keys_[DIK_DOWN] && !preKeys_[DIK_DOWN]) || (keys_[DIK_S] && !preKeys_[DIK_S])) {
		y++;
		moved = true;
	}
	if ((keys_[DIK_LEFT] && !preKeys_[DIK_LEFT])|| (keys_[DIK_A] && !preKeys_[DIK_A])) {
		x--;
		moved = true;
	}
	if ((keys_[DIK_RIGHT] && !preKeys_[DIK_RIGHT]) || (keys_[DIK_D] && !preKeys_[DIK_D])) {
		x++;
		moved = true;
	}

	// ユニットを移動
	if (moved) {
		return new UnitMoveCommand(unit, x, y);
	}

	// スペースキーで移動を決定
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		return new UnitMoveEndCommand(unit, selector_);
	}

	return nullptr;
}

bool StageSceneInputHandler::CheckUndoStatus() {
	// ctrl + ZキーでUndo
	return (keys_[DIK_Z] && !preKeys_[DIK_Z]) && keys_[DIK_LCONTROL];
}