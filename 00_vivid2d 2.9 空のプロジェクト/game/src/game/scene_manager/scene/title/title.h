#pragma once
#include"..\scene.h"


class CTitle :public IScene
{
	public:
		//初期化
		void Initialize(void)override;//多重定義
		//更新
		void Update(void)override;
		//描画
		void Draw(void)override;
		//解放
		void Finalize(void)override;


	CTitle(void) = default;//コンストラクタ
	~CTitle(void) = default;//デストラクタ

	
private:

};