#include"title.h"
#include"..\..\scene_manager.h"
#include"..\gamemain\stage\stage_manager.h"
#include"..\gamemain\story\story_manager.h"

const vivid::Vector2 pos = { vivid::WINDOW_WIDTH / 2,(vivid::WINDOW_HEIGHT * 2) / 3 };

//初期化
void CTitle::Initialize(void)
{
	/* 画像を読み込んで計算 */
	vivid::LoadTexture("data\\start.png");
	CTitle::start_logo.x = (vivid::WINDOW_WIDTH - vivid::GetTextureWidth("data\\start.png")) / 2.0f;//ｘ座標
	CTitle::start_logo.y = (vivid::WINDOW_HEIGHT - vivid::GetTextureHeight("data\\start.png")) * 2 / 3;//ｙ座標


	CStory::GetInstance().Initialize();  //ゲーム開始時に1回だけ
	CStage::GetInstance().Initialize();

}

//更新
void CTitle::Update(void)
{
	
	//キーボード用
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
	{
	
		CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);
	}
	//コントローラー用
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);
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

