#include "ClearScene.h"
#include <Novice.h>

void ClearScene::Initialize() {

}

void ClearScene::Update(InPutManager* inputManager) {
	// スペースキーで次のシーンに切り替える
	if (inputManager->GetPreKeys()[DIK_SPACE] == 0 && inputManager->GetKeys()[DIK_SPACE] != 0) {
		sceneNo = static_cast<int>(Scene::TITLE);
	}

}

void ClearScene::Draw() {
	// 現在のシーン名を描画
	Novice::ScreenPrintf(16, 16, "ClearScene");
	// 操作説明を描画
	Novice::ScreenPrintf(16, 48, "ChangeScene : Press SPACE");
}