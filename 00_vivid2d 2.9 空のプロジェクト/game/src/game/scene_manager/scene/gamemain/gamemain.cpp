#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"
#include"../../../object/map/forest/forest.h"
#include"../../../object/character/protagonist/protagonist.h"
#include"../../../object/timer/timer.h"
CForest fore;
CProtagonist protagonist;
//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート
//親クラスの作成
//初期化
void CGamemain::Initialize(void)
{
	fore.Initialize();
	protagonist.Initialize();
	CTimer::GetInstanse().Initialize();
	CStory::GetInstance().Initialize();//初期化呼び出し
}

//更新
void CGamemain::Update(void)
{
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
	{
		CStory::GetInstance().Change(STORY_ID::OPNING);
	
	}
	CTimer::GetInstanse().Update();
	protagonist.Update();
	CStory::GetInstance().Update();//更新呼び出し
}

//描画
void CGamemain::Draw(void)
{
	CStory::GetInstance().Draw();//描画呼び出し
	vivid::DrawText(48, "menu", { 0,0 });
	fore.Draw();
	protagonist.Draw();
	CTimer::GetInstanse().Draw();

}

//解放
void CGamemain::Finalize(void)
{
	CStory::GetInstance().Finalize();//解放呼び出し

}

