#pragma once

class Selector;
class Unit;

class IStageSceneCommand {
public:
	virtual ~IStageSceneCommand() = default;
	virtual void Exec() = 0;
};

class SelectMoveCommand : public IStageSceneCommand {
public:
	SelectMoveCommand(Selector* selector, int x, int y);
	void Exec() override;
private:
	Selector* selector_;
	int x_;
	int y_;
};

class SelectUnitCommand : public IStageSceneCommand {
public:
	SelectUnitCommand(Selector* selector);

	void Exec() override;
private:
	Selector* selector_;
};

class UnitMoveCommand : public IStageSceneCommand {
public:
	UnitMoveCommand(Unit* unit, int x, int y);
	void Exec() override;
private:

	Unit* unit_;
	int x_;
	int y_;
};

class UnitMoveEndCommand : public IStageSceneCommand {
public:
	UnitMoveEndCommand(Unit* unit, Selector* selector);

	void Exec() override;

private:
	Unit* unit_;
	Selector* selector_;
};