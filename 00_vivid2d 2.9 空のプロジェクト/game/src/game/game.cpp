#include"game.h"
#include"../game/scene_manager/scene_manager.h"

void CGame::Initialize(void)
{
	CSceneManager::GetInstance().Initialize();//初期化の呼び出し
}

void CGame::Update(void)
{
	CSceneManager::GetInstance().Update();//アップデートの呼び出し
}

void CGame::Draw(void)
{
	CSceneManager::GetInstance().Draw();//描画の呼び出し
}

void CGame::Finalize(void)
{
	CSceneManager::GetInstance().Finalize();//解放の呼び出し
}
