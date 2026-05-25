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

#if 0  /* タイトル処理 */
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::T))
	{

		CSceneManager::GetInstance().Change(SCENE_ID::TITLE);
	}
#endif //0
	
	/* ステージに移行 */
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::SPACE))
	{
		CStage::GetInstance().ChangeStage(STAGE_ID::STAGE1);
	}

}

void CStory1::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}

void CStory1::Finalize(void)
{

}