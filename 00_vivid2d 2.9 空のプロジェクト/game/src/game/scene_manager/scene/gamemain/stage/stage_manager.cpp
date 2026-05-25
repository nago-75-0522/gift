#include"stage_manager.h"
#include"stage1/stage1.h"

//初期値の設定
CStage::CStage()
	:m_Stage(nullptr)
	, m_Current_StageID(STAGE_ID::STAGE1)
	, m_Next_StageID(STAGE_ID::STAGE1)
{
}

CStage& CStage::GetInstance()
{
	static CStage instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

//初期化
void CStage::Initialize(void)
{
	_ChangeStage();
	if (m_Stage)
	{
		m_Stage->Initialize();
		m_Current_StageID = m_Next_StageID;
	}

}

//更新
void CStage::Update(void)
{
	if (m_Current_StageID != m_Next_StageID)
	{
		_ChangeStage();
		if (m_Stage)
			m_Stage->Initialize();

		m_Current_StageID = m_Next_StageID;
	}


	if (m_Stage)
		m_Stage->Update();
}

//描画
void CStage::Draw(void)
{
	if (m_Stage)
		m_Stage->Draw();
}

//解放
void CStage::Finalize(void)
{

}

void CStage::ChangeStage(STAGE_ID id)
{

	//呼び出されたシーンをいれる
	m_Next_StageID = id;

}

//ストーリー切り替え
void CStage::_ChangeStage()
{
	if (m_Stage)
		m_Stage->Finalize();

	delete m_Stage;
	m_Stage = nullptr;

	switch (m_Next_StageID)
	{
	case STAGE_ID::STAGE1:
		m_Stage = new CStage1();
		break;


	case STAGE_ID::STAGE2:
		break;


	case STAGE_ID::STAGE3:
		break;


	case STAGE_ID::STAGE4:
		break;


	case STAGE_ID::STAGE5:
		break;


	default:
		break;
	}
}


