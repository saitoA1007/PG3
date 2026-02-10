#include <iostream>

// 図形のインターフェース
class IShape {
public:
	virtual ~IShape() = default;

	// 面積を計算して返す関数
	virtual float Size() const = 0;

	// 結果を描画する関数
	virtual void Draw() const = 0;
};

// 円
class Circle : public IShape {
private:
	// 半径
	float radius_;

public:
	Circle(float r) : radius_(r) {}

	float Size() const override {
		return radius_ * radius_ * 3.14f;
	}

	void Draw() const override {
		std::cout << "Circle Area: " << Size() << std::endl;
	}
};

// 長方形
class Rectangle : public IShape {
private:
	// 幅
	float width_;
	// 高さ
	float height_;

public:
	Rectangle(float w, float h) : width_(w), height_(h) {}

	float Size() const override {
		return width_ * height_;
	}

	void Draw() const override {
		std::cout << "Rectangle Area: " << Size() << std::endl;
	}
};

int main() {
	const int kShapeCount = 3;
	IShape* shapes[kShapeCount];

	// 図形を生成
	shapes[0] = new Circle(5.0f);
	shapes[1] = new Rectangle(4.0f, 6.0f);
	shapes[2] = new Circle(10.0f);

	// 図形を描画する
	for (int i = 0; i < kShapeCount; ++i) {
		shapes[i]->Draw();
	}

	// メモリ解放
	for (int i = 0; i < kShapeCount; ++i) {
		delete shapes[i];
	}
	return 0;
}