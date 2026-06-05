#include"story2.h"
#include"vivid.h"
#include"..\..\..\..\scene_manager.h"
#include"..\..\stage\stage_manager.h"

CStory2& CStory2::GetInstance()
{
	static CStory2 instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CStory2::Initialize(void)
{

}

void CStory2::Update(void)
{
	//キーボード
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		//CStage::GetInstance.ChangeStage(STAGE_ID::STAGE2);
	}

	//コントローラー
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		CSceneManager::GetInstance().Change(SCENE_ID::TITLE);

	}

}

void CStory2::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}

void CStory2::Finalize(void)
{

}