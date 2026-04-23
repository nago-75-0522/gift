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
	/*
	vivid::LoadTexture("data\\space.png");//画像のロード
	space_pos.x = (vivid::WINDOW_WIDTH - vivid::GetTextureWidth("data\\space.png")) / 2.0f;//ｘ座標
	space_pos.y = (vivid::WINDOW_HEIGHT - vivid::GetTextureHeight("data\\space.png")) / 2.0f;//ｙ座標
	*/

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