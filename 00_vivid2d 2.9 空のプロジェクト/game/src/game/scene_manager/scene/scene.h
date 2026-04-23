#pragma once
#include"vivid.h"

//基底クラス(親)
class IScene//Iはインターフェース 
{
public:
	//コンストラクタ
	IScene();

	//デストラクタ
	~IScene();

	//初期化
	virtual void Initialize();

	//更新
	virtual void Update();

	//描画
	virtual void Draw();

	//解放
	virtual void Finalize();

private:

};