#include "scene_manager.h"
#include"scene/scene_id.h"

CSceneManager& CSceneManager::GetInstance()
{
	// TODO: return ステートメントをここに挿入します
}

void CSceneManager::Initialize()
{
}

void CSceneManager::Update()
{
}

void CSceneManager::Draw()
{
}

void CSceneManager::Finalize()
{
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
