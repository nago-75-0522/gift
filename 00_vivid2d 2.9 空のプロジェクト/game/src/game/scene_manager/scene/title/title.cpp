#include"title.h"

#include"vivid.h"
#include"..\..\scene_manager.h"

//‰Šú‰»
void CTitle::Initialize(void)
{
	
	

}

//XV
void CTitle::Update(void)
{
	
	
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
	
	vivid::DrawTexture("data\\gift.png", { 0,0 });
	
}

//‰ğ•ú
void CTitle::Finalize(void)
{
	
}

