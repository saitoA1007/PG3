#include "ICommand.h"
#include "Player.h"

void MoveReightCommand::Exec(Player& player) {
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player) {
	player.MoveLeft();
}