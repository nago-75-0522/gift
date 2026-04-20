#pragma once
#include"scene/scene_id.h"

class CSceneManager
{

public:
	//インスタンス呼び出す
	static CSceneManager& GetInstance();

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

	//解放
	void Finalize();

	//シーンの切り替え
	void Change(SCENE_ID id);



private:

	//コンストラクタ
	CSceneManager() = default; //なにもしない

	//デストラクタ
	~CSceneManager() = default;

	//どこからでも呼び出せるようにする
	CSceneManager(const CSceneManager& rhs) = delete;//コピーの禁止
	CSceneManager& operator =(const CSceneManager& rhs) = delete;//代入の禁止


	SCENE_ID m_CurrentID;//現在のシーンID

};

