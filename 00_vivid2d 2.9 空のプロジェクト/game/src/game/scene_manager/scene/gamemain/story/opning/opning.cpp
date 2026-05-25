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
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
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