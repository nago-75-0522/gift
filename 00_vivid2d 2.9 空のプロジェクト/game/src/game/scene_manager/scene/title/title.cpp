#include"title.h"
#include"../../../object/timer/timer.h"

//‰Šú‰»
void CTitle::Initialize(void)
{
	CTimer::GetInstanse().Initialize();
}

//XV
void CTitle::Update(void)
{
	CTimer::GetInstanse().Update();
	
}

//•`‰æ
void CTitle::Draw(void)
{
	CTimer::GetInstanse().Draw();
	
}

//‰ğ•ú
void CTitle::Finalize(void)
{
	
}

