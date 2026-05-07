#include "scene_manager.h"

CSceneManager::CSceneManager()
	:m_Scene(nullptr)
{
}

CSceneManager& CSceneManager::GetInstance()
{
	static CSceneManager instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CSceneManager::Initialize()
{
	_ChangeScene();
	if (m_Scene)
	{
		m_Scene->Initialize();
		m_CurrentID = m_NextID;
	}

}

void CSceneManager::Update()
{
	if (m_CurrentID != m_NextID)
	{
		_ChangeScene();
		if (m_Scene)
			m_Scene->Initialize();
	}

	if (!m_Scene)
		return;

	m_Scene->Update();

}

void CSceneManager::Draw()
{
	if (m_Scene)
		m_Scene->Draw();
}

void CSceneManager::Finalize()
{

}

void CSceneManager::Change(SCENE_ID id)
{
	//元のシーンを解放
	//CSceneManager::Finalize();

	//呼び出されたシーンをいれる
	m_NextID = id;//id次のやつ

	//切り替え先のシーンを初期化
	//CSceneManager::Initialize();

}

void CSceneManager::_ChangeScene()
{
	if (m_Scene)
		m_Scene->Finalize();

	
	delete m_Scene;
	m_Scene = nullptr;

	//セーブは使う場合
	switch (m_NextID)
	{
	case SCENE_ID::TITLE:
		m_Scene = new CTitle();
		break;
	case SCENE_ID::GAMEMAIN:
		m_Scene = new CGamemain();
		break;
		//case SCENE_ID::SAVE:
			//break;
	default:
		break;
	}

	if (m_Scene)
		m_Scene->Initialize();

	m_CurrentID = m_NextID;
}
