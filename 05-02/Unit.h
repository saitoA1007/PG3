#pragma once

class Selector;

class Unit {
public:
	Unit();

	void Initialize(int idref);
	void Update();
	void Draw();

	void Move(int x, int y);
	void MoveEnd(Selector* selector);

	int GetMapX()const { return mapX_; }
	int GetMapY()const { return mapY_; }

	void SetIsSelected(bool isSelected) { isSelected_ = isSelected; }

private:
	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = 32;
	int id = 0;
	bool isSelected_ = false;
};