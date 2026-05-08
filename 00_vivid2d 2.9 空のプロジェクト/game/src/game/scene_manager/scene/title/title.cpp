#include"title.h"
#include"../../../object/timer/timer.h"
#include"vivid.h"
#include"..\..\scene_manager.h"
#include"../../../object/map/forest/forest.h"

CForest forest;
//‰Šú‰»
void CTitle::Initialize(void)
{
	forest.Initialize();
	CTimer::GetInstanse().Initialize();
}

//XV
void CTitle::Update(void)
{
	
	CTimer::GetInstanse().Update();
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Z))
	{
		CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);

#if _DEBUG
		
#endif
	}
}

//•`‰æ
void CTitle::Draw(void)
{
	forest.Draw();
	CTimer::GetInstanse().Draw();
	vivid::DrawTexture("data\\gift.png", { 0,0 });
	
}

//‰ğ•ú
void CTitle::Finalize(void)
{
	
}

