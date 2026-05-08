#include"story_manager.h"
#include"story1/story1.h"

CStory& CStory::GetInstance()
{
	static CStory instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

CStory::CStory()
	:m_Story(nullptr)
{
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
	}

	if (!m_Story)
		return;

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
	//元のシーンを解放
	CStory::Finalize();

	//呼び出されたシーンをいれる
	m_Next_StoryID = id;//id次のやつ

	//切り替え先のシーンを初期化
	CStory::Initialize();
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
		//m_Story = new COpning();
		Opning();
		break;

	case STORY_ID::STORY1:
		//m_Story = new CStory1();
		break;
	}
}


//op
void CStory::Opning(void)
{

	vivid::DrawTexture("data\\op.png", { 0,0 });
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
		CStory::GetInstance().Change(STORY_ID::STORY1);
	}
}

void CStory::Story1(void)
{
	CStory1::GetInstance().Draw();
}

