#include"stage1.h"
#include"vivid.h"
#include"..\..\story\story_manager.h"

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

        // ★ GameMain に「ステージへ行きたい」と知らせる
        CStory::GetInstance().m_RequestStage = true;
    }
}

void CStage1::Draw(void)
{
	vivid::DrawText(48, "stage1", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xfffffffff);

}

void CStage1::Finalize(void)
{

}