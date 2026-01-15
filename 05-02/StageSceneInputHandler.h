#pragma once

class IStageSceneCommand;

class Selector;
class Unit;

class StageSceneInputHandler {
public:
	StageSceneInputHandler();
	
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();

	void SetSelector(Selector* selector) { selector_ = selector;}

private:
	char keys_[256] = {};
	char preKeys_[256] = {};

	Selector* selector_;
	Unit* selectedUnit_;
};