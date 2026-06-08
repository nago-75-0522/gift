#include"../../../../../object/character/protagonist/protagonist.h"
#include"../../../../../object/map/forest_manager/forest/forest.h"
#include"../../../../../object/map/forest_manager/fog/fog.h"
#include"../../../../../object/map/forest_manager/forest_manager.h"
#include"../../../../../object/timer/timer.h"
#include"opning.h"
#include"opning.h"
#include"vivid.h"
#include"..\story_manager.h"

COpning& COpning::GetInstance()
{
	static COpning instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
	
}


//親クラスの作成
//初期化
void COpning::Initialize(void)
{
	//ステージ３の森とキャラ（仮）
#if 0
	CForest_Manager::GetInstance().Initialize();
	CForest::GetInstance().Initialize();
	CProtagonist::GetInstance().Initialize();
	CFog::GetInstance().Initialize();
	CTimer::GetInstanse().Initialize();
#endif

}

//更新
void COpning::Update(void)
{
	//ステージ３の森とキャラ（仮）
#if 0
	CForest::GetInstance().Update();
	CProtagonist::GetInstance().Update();
	CForest_Manager::GetInstance().Update();
	CFog::GetInstance().Update();
	CTimer::GetInstanse().Update();
#endif
	//キーボード用
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		CStory::GetInstance().ChangeStory(STORY_ID::STORY1);
	}
	//コントローラー
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		CStory::GetInstance().ChangeStory(STORY_ID::STORY1);
	}
}


void COpning::Draw(void)
{
	//ステージ３の森とキャラ（仮）
#if 0
	CForest::GetInstance().Draw();
	CProtagonist::GetInstance().Draw();
	CForest_Manager::GetInstance().Draw();
	CFog::GetInstance().Draw();
	CTimer::GetInstanse().Draw();
#endif
	vivid::DrawText(48, "opning", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xfffffffff);
}



void COpning::Finalize(void)
{
}

