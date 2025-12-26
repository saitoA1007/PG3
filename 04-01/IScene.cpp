#include "IScene.h"

// タイトルシーンで初期化
int IScene::sceneNo = static_cast<int>(Scene::TITLE);

// シーン番号のゲッター
int IScene::GetScene() { return sceneNo; }