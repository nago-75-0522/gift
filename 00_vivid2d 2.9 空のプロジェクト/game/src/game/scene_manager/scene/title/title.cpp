#include"title.h"
#include"../../../object/timer/timer.h"
#include"vivid.h"
#include"..\..\scene_manager.h"


//‰Šú‰»
void CTitle::Initialize(void)
{
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
		vivid::DrawText(48, "ok", { 100,100 });
#endif
	}
}

//•`‰æ
void CTitle::Draw(void)
{
	CTimer::GetInstanse().Draw();
	vivid::DrawText(48, "title", {0,0});
	
}

//‰ğ•ú
void CTitle::Finalize(void)
{
	
}

