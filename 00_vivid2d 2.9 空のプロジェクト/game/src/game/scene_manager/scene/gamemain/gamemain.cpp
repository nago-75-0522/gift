#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"

//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート
//親クラスの作成
//初期化
void CGamemain::Initialize(void)
{
	
	CStory::GetInstance().Initialize();//初期化呼び出し
}

//更新
void CGamemain::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
	{
		CStory::GetInstance().Change(STORY_ID::OPNING);
	
	}
	CStory::GetInstance().Update();//更新呼び出し
}

//描画
void CGamemain::Draw(void)
{
	CStory::GetInstance().Draw();//描画呼び出し
	vivid::DrawText(48, "menu", { 0,0 });
	

}

//解放
void CGamemain::Finalize(void)
{
	CStory::GetInstance().Finalize();//解放呼び出し

}

