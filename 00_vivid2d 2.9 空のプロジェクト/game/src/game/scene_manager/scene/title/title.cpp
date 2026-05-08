#include"title.h"
#include"../../../object/timer/timer.h"
#include"vivid.h"
#include"..\..\scene_manager.h"
#include"../../../object/map/forest/forest.h"
#include"../../../object/character/protagonist/protagonist.h"
CForest fore;
CProtagonist protagonist;
//èâä˙âª
void CTitle::Initialize(void)
{
	fore.Initialize();
	protagonist.Initialize();
	CTimer::GetInstanse().Initialize();

}

//çXêV
void CTitle::Update(void)
{
	
	CTimer::GetInstanse().Update();
	protagonist.Update();
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::Z))
	{
		CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);

#if _DEBUG
		vivid::DrawText(48, "ok", { 100,100 });
#endif
	}
}

//ï`âÊ
void CTitle::Draw(void)
{
	fore.Draw();
	protagonist.Draw();
	CTimer::GetInstanse().Draw();
	vivid::DrawText(48, "title", {0,0});
	
}

//âï˙
void CTitle::Finalize(void)
{
	
}

