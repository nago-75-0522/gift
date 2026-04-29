#include"title.h"
#include"vivid.h"
#include"..\..\scene_manager.h"
CTitle& CTitle::GetInstance()
{
	static CTitle instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す

}


//初期化
void CTitle::Initialize(void)
{
	
}

//更新
void CTitle::Update(void)
{

	
}

//描画
void CTitle::Draw(void)
{
	

}

//解放
void CTitle::Finalize(void)
{
	
}