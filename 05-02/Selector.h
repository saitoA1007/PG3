#pragma once
#include <vector>

class Unit;

// 操作モード
enum class Mode {
	SELECTOR, // 選択モード
	UNIT      // ユニットを動かすモード
};

class Selector {
public:
	Selector();

	void Initialize();

	void Update();

	void Draw();

	void Move(int x, int y);
	void SelectUnit();

	int GetSelectMode() { return selectMode_; }
	void SetSelectMode(int mode) { selectMode_ = mode; }

	Unit* GetSelectedUnitAddress() { return selectedUnit_; }
	void SetSelectedUnit(Unit* unit) { selectedUnit_ = unit; }

	int GetMapX()const { return mapX_; }
	int GetMapY()const { return mapY_; }

	void SetUnits(const std::vector<Unit*>& units) { unit_ = units; }
	const std::vector<Unit*>& GetUnits() const { return unit_; }

private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int selectMode_;

	std::vector<Unit*> unit_;
	Unit* selectedUnit_;
};