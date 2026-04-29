#include "scene_manager.h"
#include"scene/scene_id.h"
#include"..\scene_manager\scene\title\title.h"

CSceneManager& CSceneManager::GetInstance()
{
	static CSceneManager instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CSceneManager::Initialize()
{
	switch (m_CurrentID)
	{
	case SCENE_ID::TITLE:
		
		break;
	case SCENE_ID::GAMEMAIN:
		break;
		/*
	case SCENE_ID::STAGE1:
		break;
	case SCENE_ID::STAGE2:
		break;
	case SCENE_ID::STAGE3:
		break;
	case SCENE_ID::STAGE4:
		break;
	case SCENE_ID::ENDING:
		break;
		*/
	default:
		break;
	}
}

void CSceneManager::Update()
{

	switch (m_CurrentID)
	{
	case SCENE_ID::TITLE:
		
		break;
	case SCENE_ID::GAMEMAIN:
		break;
		/*
	case SCENE_ID::STAGE1:
		break;
	case SCENE_ID::STAGE2:
		break;
	case SCENE_ID::STAGE3:
		break;
	case SCENE_ID::STAGE4:
		break;
	case SCENE_ID::ENDING:
		break;
		*/
	default:
		break;
	}

}

void CSceneManager::Draw()
{

	switch (m_CurrentID)
	{
	case SCENE_ID::TITLE:
	
		CTitle::GetInstance().Draw();
		vivid::DrawText(40, "たいとる", vivid::Vector2::ZERO);
		break;
	case SCENE_ID::GAMEMAIN:
		//初めから　続きから＝続きからだったらセーブデータのシーン
		//初めからだったらすとーりー1にとぶ
		break;


	default:
		break;
	}

}

void CSceneManager::Finalize()
{

	switch (m_CurrentID)
	{
	case SCENE_ID::TITLE:
		CTitle::GetInstance().Update();
#ifndef DEBUG
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		{
			Change(SCENE_ID::GAMEMAIN);
		}
#endif // !_DEBUG
		break;
	case SCENE_ID::GAMEMAIN:
		break;

		/*
	case SCENE_ID::STAGE1:
		break;
	case SCENE_ID::STAGE2:
		break;
	case SCENE_ID::STAGE3:
		break;
	case SCENE_ID::STAGE4:
		break;
	case SCENE_ID::ENDING:
		break;
		*/
	default:
		break;
	}

}

void CSceneManager::Change(SCENE_ID id)
{
	//元のシーンを解放
	CSceneManager::Finalize();

	//呼び出されたシーンをいれる
	m_CurrentID = id;//id次のやつ

	//切り替え先のシーンを初期化
	CSceneManager::Initialize();

}
