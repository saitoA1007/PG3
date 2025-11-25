#include<iostream>
#include<numbers>

class IShape {
public:
	virtual ~IShape() = default;

	// 面積の計算
	virtual void Size() = 0;

	// 面積を描画
	virtual void Draw() = 0;
};

// 円
class Circle : public IShape {
public:
	Circle(float radius) : radius_(radius), area_(0.0f) {}

	void Size() override {
		area_ = std::numbers::pi_v<float> * radius_ * radius_;
	}

	void Draw() override {
		std::cout << "Circle Area : " << area_ << std::endl;
	}

private:
	float radius_;
	float area_;
};

// 矩形
class Rectangle : public IShape {
public:
	Rectangle(float width, float height) : width_(width), height_(height), area_(0.0f) {}

	void Size() override {
		area_ = width_ * height_;
	}

	void Draw() override {
		std::cout << "Rectangle Area : " << area_ << std::endl;
	}

private:
	float width_;
	float height_;
	float area_;
};

int main() {
	// 生成
	IShape* circle = new Circle(5.0f);
	IShape* rectangle = new Rectangle(8.0f, 4.0f);

	// 円
	circle->Size();
	circle->Draw();

	// 矩形
	rectangle->Size();
	rectangle->Draw();

	// 削除
	delete circle;
	delete rectangle;
	return 0;
}