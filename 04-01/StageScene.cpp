#include "StageScene.h"
#include <Novice.h>
#include <cmath>

void StageScene::Initialize() {

	// プレイヤーを初期化
	player_.pos = { 100.0f,200.0f };
	player_.radius = 16.0f;
	player_.isAlive = true;

	// 敵を初期化
	enemy_.pos = { 800.0f,200.0f };
	enemy_.radius = 32.0f;
	enemy_.isAlive = true;

	// 弾を初期化
	bullet_.pos = { 0.0f,0.0f };
	bullet_.radius = 8.0f;
	bullet_.isAlive = false;
	isBulletShot_ = false;
}

void StageScene::Update(InPutManager* inputManager) {
	// 敵が倒された時、クリアシーンに遷移する
	if (!enemy_.isAlive) {
		sceneNo = static_cast<int>(Scene::CLEAR);
	}

	//================================================================
	// 弾の更新処理
	//================================================================

	// 発射フラグが無効の時、発射可能
	if (!isBulletShot_) {
		// 弾を発射する
		if (!inputManager->GetPreKeys()[DIK_SPACE] && inputManager->GetKeys()[DIK_SPACE]) {
			// 発射フラグを有効
			isBulletShot_ = true;
			// 弾の生存フラグを有効化
			bullet_.isAlive = true;
			// 弾をプレイヤーの位置に設定
			bullet_.pos = player_.pos;
		}
	}
	
	// 弾の移動処理
	if (bullet_.isAlive) {
		// 弾の移動
		bullet_.pos.x += bulletSpeed_ * kDeltaTime;

		// 弾が画面外に出たら無効化する
		if (bullet_.pos.x >= 1280.0f) {
			// 弾の生存フラグを無効
			bullet_.isAlive = false;
			// 弾の発射フラグを無効
			isBulletShot_ = false;
		}
	}

	//========================================================================================
	// 弾と敵の当たり判定
	//========================================================================================

	// 敵と弾の生存フラグが有効の時
	if (enemy_.isAlive && bullet_.isAlive) {
		// 敵と弾の間の距離を求める
		Vector2 triangle = enemy_.pos - bullet_.pos;
		float distance = std::sqrtf(triangle.x * triangle.x + triangle.y * triangle.y);

		// 弾と敵の半径の合計より弾と敵の距離が小さい時
		if (distance <= bullet_.radius + enemy_.radius) {
			// 敵の生存フラグを無効
			enemy_.isAlive = false;
			// 弾の生存フラグを無効
			bullet_.isAlive = false;
			// 弾の発射フラグを無効
			isBulletShot_ = false;
		}
	}
}

void StageScene::Draw() {

	// プレイヤーを描画
	if (player_.isAlive) {
		Novice::DrawEllipse(
			static_cast<int>(player_.pos.x), static_cast<int>(player_.pos.y),
			static_cast<int>(player_.radius), static_cast<int>(player_.radius),
			0.0f, 0xFFFFFFFF, kFillModeSolid);
	}

	// 敵を描画
	if (enemy_.isAlive) {
		Novice::DrawEllipse(
			static_cast<int>(enemy_.pos.x), static_cast<int>(enemy_.pos.y),
			static_cast<int>(enemy_.radius), static_cast<int>(enemy_.radius),
			0.0f, 0xFF0000FF, kFillModeSolid);
	}

	// 弾を描画
	if (bullet_.isAlive) {
		Novice::DrawEllipse(
			static_cast<int>(bullet_.pos.x), static_cast<int>(bullet_.pos.y),
			static_cast<int>(bullet_.radius), static_cast<int>(bullet_.radius),
			0.0f, 0x0000FFFF, kFillModeSolid);
	}

	// 現在のシーン名を描画
	Novice::ScreenPrintf(16, 16, "StageScene");
	// 操作説明を描画
	Novice::ScreenPrintf(16, 48, "BulletShot : Press SPACE");
}