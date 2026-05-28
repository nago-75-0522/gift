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
		CStage::GetInstance().ChangeStage(STAGE_ID::STAGE1);
		CStory::GetInstance().m_RequestStage = true;
	}

	//コントローラー
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		CStage::GetInstance().ChangeStage(STAGE_ID::STAGE1);
		CStory::GetInstance().m_RequestStage = true;
	}

}

void CStory1::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}

void CStory1::Finalize(void)
{

}