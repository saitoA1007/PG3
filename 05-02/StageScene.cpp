#include "StageScene.h"
#include <Novice.h>
#include <cmath>

void StageScene::Initialize() {
	// セレクタの初期化
	selector_ = new Selector();
	selector_->Initialize();

	// ユニットを3体配置
	units_.push_back(new Unit());
	units_[0]->Initialize(0);
	units_[0]->Move(5, 5);

	units_.push_back(new Unit());
	units_[1]->Initialize(1);
	units_[1]->Move(10, 8);

	units_.push_back(new Unit());
	units_[2]->Initialize(2);
	units_[2]->Move(15, 12);

	// セレクタにユニット配列を設定
	selector_->SetUnits(units_);

	// インプットハンドラの初期化
	inputHandler_ = new StageSceneInputHandler();
	inputHandler_->SetSelector(selector_);

	// コマンド履歴の初期化
	commandHistory_.clear();
	commandHistoryItr_ = commandHistory_.end();
	command_ = nullptr;
}

void StageScene::Update() {
	
	// 入力処理の更新
	inputHandler_->UpdateKeyState();

	// Undoの確認
	if (inputHandler_->CheckUndoStatus() && selector_->GetSelectMode() == static_cast<int>(Mode::UNIT)) {
		// イテレータがbeginより後ろにあり、履歴が空でない場合
		if (!commandHistory_.empty() && commandHistoryItr_ != commandHistory_.begin()) {
			// イテレータを1つ前に戻す
			--commandHistoryItr_;
			// その位置のコマンドを実行
			(*commandHistoryItr_)->Exec();
		}
		return;
	}

	if (selector_->GetSelectMode() == static_cast<int>(Mode::SELECTOR)) {
		command_ = inputHandler_->SelectorHandleInput(selector_);
	} else if (selector_->GetSelectMode() == static_cast<int>(Mode::UNIT)) {
		command_ = inputHandler_->UnitHandleInput(selector_->GetSelectedUnitAddress());
	}

	if (command_) {
		command_->Exec();

		// 履歴を保存
		if (commandHistory_.empty()) {
			commandHistory_.push_back(command_);
			commandHistoryItr_ = commandHistory_.end();
		} else if (commandHistoryItr_ == commandHistory_.end()) {
			commandHistory_.push_back(command_);
			commandHistoryItr_ = commandHistory_.end();
		} else {
			*commandHistoryItr_ = command_;
			commandHistoryItr_++;
		}
	}
}

void StageScene::Draw() {

	// マス目を描画
	for (int i = 0; i < 23; ++i) {
		Novice::DrawLine(0, i * 32, 1280, i * 32, 0xFFFFFFFF);
	}
	for (int i = 0; i < 40; ++i) {
		Novice::DrawLine(i * 32, 0, i * 32, 720, 0xFFFFFFFF);
	}

	// ユニットを描画
	for (auto unit : units_) {
		unit->Draw();
	}

	// 選択中の範囲を描画
	selector_->Draw();
}