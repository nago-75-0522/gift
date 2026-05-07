#include"gamemain.h"
#include"vivid.h"

//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート

//初期化
void CGamemain::Initialize(void)
{
	
}

//更新
void CGamemain::Update(void)
{
	

}

//描画
void CGamemain::Draw(void)
{
	vivid::DrawText(48, "gamemain", { 0,0 });

}

//解放
void CGamemain::Finalize(void)
{

}

