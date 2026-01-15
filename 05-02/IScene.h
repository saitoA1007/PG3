#pragma once
// シーン名
enum class Scene {
	STAGE
};

class IScene {
public:
	virtual ~IScene() = default;

	/// <summary>
	/// 初期化処理
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="inputManager"></param>
	virtual void Update() = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw() = 0;

	// シーン番号を取得
	int GetScene();

protected:
	// シーン番号の管理変数
	static int sceneNo;
};