#include "IScene.h"

// タイトルシーンで初期化
int IScene::sceneNo = static_cast<int>(Scene::STAGE);

// シーン番号のゲッター
int IScene::GetScene() { return sceneNo; }