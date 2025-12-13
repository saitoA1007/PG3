#include <iostream>

class Enemy {
public:

	// 更新処理
	void Update() {
		if (currentStep_ < 3) {
			// 状態に応じた処理をおこなう
			(this->*spFuncTable[currentStep_])();
		}
	}

private:
	// 現在の状態を管理
	int currentStep_ = 0;

	// 接近処理
	void Approach() {
		std::cout << "接近" << "\n";
		// 次の状態へ遷移
		currentStep_++;
	}

	// 射撃処理
	void ShotBullet() {
		std::cout << "射撃" << "\n";
		// 次の状態へ遷移
		currentStep_++;
	}

	// 離脱処理
	void Disengage() {
		std::cout << "離脱" << "\n";
		currentStep_++;
	}

	// メンバ関数テーブルの宣言
	static void (Enemy::* spFuncTable[])();
};

// 敵のメンバ関数テーブルの定義と初期化
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::Approach,   // 接近
	&Enemy::ShotBullet, // 射撃
	&Enemy::Disengage   // 離脱
};

int main() {
	// 敵を生成
	Enemy enemy;

	// 敵の更新処理
	for (int i = 0; i < 3; ++i) {
		enemy.Update();
	}
	return 0;
}