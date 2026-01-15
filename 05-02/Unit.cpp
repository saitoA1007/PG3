#include "Unit.h"
#include "Selector.h"
#include <Novice.h>

Unit::Unit() {

}

void Unit::Initialize(int idref) {
	id = idref;
}

void Unit::Update() {

}

void Unit::Draw() {
	// 描画
	if (isSelected_) {
		Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFF0000FF, kFillModeSolid);
	} else {
		Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFFFFFFFF, kFillModeSolid);
	}
}

void Unit::Move(int x, int y) {
	// 移動
	mapX_ = x;
	mapY_ = y;
}

void Unit::MoveEnd(Selector* selector) {
	// 移動を確定してセレクタモードに戻る
	isSelected_ = false;
	selector->SetSelectMode(static_cast<int>(Mode::SELECTOR));
	selector->SetSelectedUnit(nullptr);

	// ユニットの位置に移動
	selector->Move(mapX_, mapY_);
}