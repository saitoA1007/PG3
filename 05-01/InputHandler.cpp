#include"InputHandler.h"
#include<Novice.h>

ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_;
	}

	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_;
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
	ICommand* command = new MoveLeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
	ICommand* command = new MoveReightCommand();
	pressKeyD_ = command;
}