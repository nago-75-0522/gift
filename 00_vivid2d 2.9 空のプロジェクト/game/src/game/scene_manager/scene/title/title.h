#pragma once
#include"vivid.h"
#include"..\scene.h"

class CTitle :public IScene
{
	public:

		static CTitle& GetInstance();//インスタンス取得

		//初期化
		void Initialize(void)override;//多重定義
		//更新
		void Update(void)override;
		//描画
		void Draw(void)override;
		//解放
		void Finalize(void)override;



	private:

	CTitle(void) = default;//コンストラクタ
	~CTitle(void) = default;//デストラクタ

	//どこからでも呼び出せるようにする
	CTitle(const CTitle& rhs) = delete;//コピーの禁止
	CTitle& operator =(const CTitle& rhs) = delete;//代入の禁止


};