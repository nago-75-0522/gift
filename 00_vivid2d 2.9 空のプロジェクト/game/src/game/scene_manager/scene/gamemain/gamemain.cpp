#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"
#include"../../../object/map/forest_maneger/forest/forest.h"
#include"../../../object/character/protagonist/protagonist.h"
#include"../../../object/timer/timer.h"
#include"../../../object/map/forest_maneger/forest_manager.h"
//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート
//親クラスの作成
//初期化
void CGamemain::Initialize(void)
{

	CForest::GetInstance().Initialize();
	CProtagonist::GetInstance().Initialize();
	CTimer::GetInstanse().Initialize();
	CStory::GetInstance().Initialize();//初期化呼び出し
}


 void CGamemain::Update(void)
 {
	 CStory::GetInstance().Change(STORY_ID::OPNING);

	 CForest::GetInstance().Update();
	CTimer::GetInstanse().Update();
	CProtagonist::GetInstance().Update();
	CStory::GetInstance().Update();//更新呼び出し
}


void CGamemain::Draw(void)
{
	CStory::GetInstance().Draw();//描画呼び出し
	vivid::DrawText(48, "menu", { 0,0 });

	CForest::GetInstance().Draw();
	CProtagonist::GetInstance().Draw();
	CTimer::GetInstanse().Draw();

}

void CGamemain::Finalize(void)
{
}

