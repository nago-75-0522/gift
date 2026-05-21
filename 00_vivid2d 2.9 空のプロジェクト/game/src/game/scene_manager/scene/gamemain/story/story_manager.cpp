#include"story_manager.h"
#include"story1/story1.h"
#include"opning/opning.h"

//初期値の設定
CStory::CStory()
	:m_Story(nullptr)
	, m_Current_StoryID(STORY_ID::OPNING)
	, m_Next_StoryID(STORY_ID::OPNING)
{
}

CStory& CStory::GetInstance()
{
	static CStory instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

//初期化
void CStory::Initialize(void)
{
	_ChangeStory();
	if (m_Story)
	{
		m_Story->Initialize();
		m_Current_StoryID = m_Next_StoryID;
	}

}

//更新
void CStory::Update(void)
{
	if (m_Current_StoryID != m_Next_StoryID)
	{
		_ChangeStory();
		if (m_Story)
			m_Story->Initialize();

		m_Current_StoryID = m_Next_StoryID;
	}


	if (m_Story)
		m_Story->Update();
}

//描画
void CStory::Draw(void)
{
	if (m_Story)
		m_Story->Draw();
}

//解放
void CStory::Finalize(void)
{
	
}

void CStory::Change(STORY_ID id)
{

	//呼び出されたシーンをいれる
	m_Next_StoryID = id;//id次のやつ

}

//ストーリー切り替え
void CStory::_ChangeStory()
{
	if (m_Story)
		m_Story->Finalize();

	delete m_Story;
	m_Story = nullptr;
	switch (m_Next_StoryID)
	{
	case STORY_ID::OPNING:
		m_Story = new COpning();
		break;

	case STORY_ID::STORY1:
		m_Story = new CStory1();
		break;
	}
}


