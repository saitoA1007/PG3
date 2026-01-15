#include "Selector.h"
#include "Unit.h"
#include <Novice.h>

Selector::Selector() {
	mapX_ = 0;
	mapY_ = 0;
	mapSize_ = 32;
	selectMode_ = static_cast<int>(Mode::SELECTOR);
	selectedUnit_ = nullptr;
}

void Selector::Initialize() {
	mapX_ = 4;
	mapY_ = 4;
	selectMode_ = static_cast<int>(Mode::SELECTOR);
	selectedUnit_ = nullptr;
}

void Selector::Update() {

}

void Selector::Draw() {
	// 選択の枠を描画
	if (selectMode_ == static_cast<int>(Mode::SELECTOR)) {
		Novice::DrawBox(mapX_ * mapSize_, mapY_ * mapSize_, mapSize_, mapSize_, 0.0f, 0xFF0000FF, kFillModeWireFrame);
	}
}

void Selector::Move(int x, int y) {
	mapX_ = x;
	mapY_ = y;
}

void Selector::SelectUnit() {
	// セレクタの位置にユニットがあるか確認
	selectedUnit_ = nullptr;
	for (auto unit : unit_) {
		if (unit->GetMapX() == mapX_ && unit->GetMapY() == mapY_) {
			selectedUnit_ = unit;
			selectedUnit_->SetIsSelected(true);
			selectMode_ = static_cast<int>(Mode::UNIT);
			break;
		}
	}
}