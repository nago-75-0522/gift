#include"title.h"
#include"vivid.h"
#include"..\..\scene_manager.h"
#include"../../../object/timer/timer.h"
CTitle& CTitle::GetInstance()
{
	static CTitle instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す

}


//初期化
void CTitle::Initialize(void)
{
	CTimer::GetInstanse().Initialize();
}

//更新
void CTitle::Update(void)
{
	CTimer::GetInstanse().Update();
	
}

//描画
void CTitle::Draw(void)
{
	CTimer::GetInstanse().Draw();
	
}

//解放
void CTitle::Finalize(void)
{
	
}