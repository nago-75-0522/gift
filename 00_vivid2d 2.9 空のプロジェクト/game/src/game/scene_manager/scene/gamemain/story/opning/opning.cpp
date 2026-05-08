#include"opning.h"
#include"vivid.h"

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
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
	{
		CStory::GetInstance().Change(STORY_ID::STORY1);

	}
}

void COpning::Draw(void)
{
	vivid::DrawTexture("data\\op.png", { 0,0 });

}

void COpning::Finalize(void)
{

}