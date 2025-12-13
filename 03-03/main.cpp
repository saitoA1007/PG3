#include <iostream>

// 掃除道具
class CleaningItems {
public:
	virtual ~CleaningItems() = default;

	// 道具を使用する
	virtual void Use() = 0;
};

// 箒
class Broom : public CleaningItems {

	void Use() override {
		std::cout << "箒を使用しました。" << std::endl;
	}
};

// 雑巾
class Cloth : public CleaningItems {

	void Use() override {
		std::cout << "雑巾を使用しました。" << std::endl;
	}
};

int main() {
	// 掃除道具
	CleaningItems* CleaningItem_eaters[3];

	// 道具を生成する
	for (int i = 0; i < 3; ++i) {
		if (i == 1) {
			CleaningItem_eaters[i] = new Broom;
		} else {
			CleaningItem_eaters[i] = new Cloth;
		}
	}

	// 道具を使用する
	for (int i = 0; i < 3; ++i) {
		CleaningItem_eaters[i]->Use();
	}

	// 破棄する
	for (int i = 0; i < 3; ++i) {
		delete CleaningItem_eaters[i];
	}
	return 0;
}