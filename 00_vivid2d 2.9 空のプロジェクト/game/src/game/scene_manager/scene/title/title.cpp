#include"title.h"
#include"..\..\scene_manager.h"


const vivid::Vector2 pos = { vivid::WINDOW_WIDTH / 2,(vivid::WINDOW_HEIGHT * 2) / 3 };

//初期化
void CTitle::Initialize(void)
{
	/* 画像を読み込んで計算 */
	vivid::LoadTexture("data\\start.png");
	CTitle::start_logo.x = (vivid::WINDOW_WIDTH - vivid::GetTextureWidth("data\\start.png")) / 2.0f;//ｘ座標
	CTitle::start_logo.y = (vivid::WINDOW_HEIGHT - vivid::GetTextureHeight("data\\start.png")) * 2 / 3;//ｙ座標

}

//更新
void CTitle::Update(void)
{
	
	
	if (vivid::keyboard::Button(vivid::keyboard::KEY_ID::SPACE))
	{
	
		CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);

#if _DEBUG		
#endif

	}
}

//描画
void CTitle::Draw(void)
{
	vivid::DrawTexture("data\\gift.png", { 0,0 });
	vivid::DrawTexture("data\\start.png", start_logo);

	

}

//解放
void CTitle::Finalize(void)
{
	
}

