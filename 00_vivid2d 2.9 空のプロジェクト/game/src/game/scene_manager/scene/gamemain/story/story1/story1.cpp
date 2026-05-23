#include"story1.h"
#include"vivid.h"
#include"..\..\..\..\scene_manager.h"

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


	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::T))
	{

		CSceneManager::GetInstance().Change(SCENE_ID::TITLE);
	}
}

void CStory1::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}

void CStory1::Finalize(void)
{

}