#include"story1.h"
#include"vivid.h"
#include"..\..\..\..\scene_manager.h"
#include"..\..\stage\stage_manager.h"

CStory1& CStory1::GetInstance()
{
	static CStory1 instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CStory1::Initialize(void)
{

}

void CStory1::Update(void)
{
	//キーボード
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		//GameMainに「今はステージモード」と伝える
		CGamemain::GetInstance().SetGameState(CGamemain::GAME_STATE::STORY);

		//STAGEシーンへ遷移
		CSceneManager::GetInstance().Change(SCENE_ID::STAGE);
	}

	//コントローラー
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		//GameMainに今はステージモードを知らせる
		CGamemain::GetInstance().SetGameState(CGamemain::GAME_STATE::STORY);

		//STAGEシーンへ遷移
		CSceneManager::GetInstance().Change(SCENE_ID::STAGE);

	}

}

void CStory1::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}

void CStory1::Finalize(void)
{

}