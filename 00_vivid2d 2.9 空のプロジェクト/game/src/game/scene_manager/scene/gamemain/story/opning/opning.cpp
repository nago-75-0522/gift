#include"opning.h"
#include"vivid.h"
#include"..\story_manager.h"

COpning& COpning::GetInstance()
{
	static COpning instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void COpning::Initialize(void)
{

}

void COpning::Update(void)
{
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
	vivid::DrawText(48, "opning", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xfffffffff);

}

void COpning::Finalize(void)
{

}