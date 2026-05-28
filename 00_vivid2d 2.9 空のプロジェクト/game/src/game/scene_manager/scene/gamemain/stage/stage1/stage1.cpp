#include"stage1.h"
#include"vivid.h"
#include"..\..\story\story_manager.h"
#include"..\..\..\..\scene_manager.h"

CStage1& CStage1::GetInstance()
{
	static CStage1 instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CStage1::Initialize(void)
{
	
}

void CStage1::Update(void)
{
    if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
    {

        CStage::GetInstance().ChangeStage(STAGE_ID::STAGE1);
        //GameMainにストーリーへ行きたいと知らせる
        CStory::GetInstance().m_RequestStage = true;
    }

#if 1
    if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
    {
        //いったんタイトル戻る
        CSceneManager::GetInstance().Change(SCENE_ID::TITLE);
    }

#endif 1
}

void CStage1::Draw(void)
{
	vivid::DrawText(48, "stage1", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xfffffffff);

}

void CStage1::Finalize(void)
{

}