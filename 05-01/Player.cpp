#include "Player.h"
#include <Novice.h>

Player::Player() {
}

void Player::Initialize() {
	pos_ = { 640.0f,360.0f };
	size_ = { 32.0f,32.0f };
}

void Player::Update() {

}

void Player::Draw() {
	// プレイヤーを描画
	Novice::DrawBox(static_cast<int>(pos_.x - size_.x * 0.5f), static_cast<int>(pos_.y - size_.y * 0.5f),
		static_cast<int>(size_.x), static_cast<int>(size_.y), 
		0.0f, 0xFFFFFFFF, kFillModeSolid);
}

void Player::MoveRight() {
	pos_.x += speed_;
}
void Player::MoveLeft() {
	pos_.x -= speed_;
}