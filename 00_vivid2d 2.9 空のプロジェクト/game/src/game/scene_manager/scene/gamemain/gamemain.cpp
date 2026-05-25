#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"
#include"stage/stage_manager.h"
//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート

//定数
const vivid::Vector2 CGamemain::m_BG_Position(0.0f, 0.0f);
const int CGamemain::m_Button_x[]{ 230, 810 };
const int CGamemain::m_Button_y(vivid::WINDOW_HEIGHT / 2);
const int CGamemain::m_Finger_Width(230);
const std::string CGamemain::m_Button_Image[] = { "data\\first.png","data\\second.png" };
const unsigned int CGamemain::m_Select_Button_Color(0xffffffff);



//親クラスの作成
//初期化
void CGamemain::Initialize(void)
{
	m_Now_Select = SELECT_BUTTON::START;
	m_Now_GameState = GAME_STATE::MENU;

	m_Button_Position = vivid::Vector2::ZERO;//位置
	//ｘは配列に合わせるため
	m_Finger_Position.x = m_Button_x[(int)m_Now_Select] - m_Finger_Width;//指のｘ座標の初期化
	//矢印yは選択中ボタンの高さと変わらないため
	m_Finger_Position.y = m_Button_y;									//指のy座標の初期化

}

//更新
void CGamemain::Update(void)
{
		switch (m_Now_GameState)
		{
			//MENU
		case GAME_STATE::MENU:
			Menu();

			if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
			{
				if (m_Now_Select == SELECT_BUTTON::START)
					CStory::GetInstance().ChangeStory(STORY_ID::OPNING);
				else
					CStory::GetInstance().ChangeStory(STORY_ID::STORY1);

				m_Now_GameState = GAME_STATE::STORY;
			}
			break;


			
			// STORY
		case GAME_STATE::STORY:
			CStory::GetInstance().Update();
			//Story側がStageに行きたいときにtrueにする
			if (CStory::GetInstance().m_RequestStage == true)
			{
				CStory::GetInstance().m_RequestStage = false;
				m_Now_GameState = GAME_STATE::STAGE;
			}
		
			break;


			
			//STAGE
		case GAME_STATE::STAGE:
			CStage::GetInstance().Update();
			break;
		}
	}

void CGamemain::Draw(void)
{
		switch (m_Now_GameState)
		{
			
			//MENU
		case GAME_STATE::MENU:
			CGamemain::DrawMenu();
		
			break;


			//STORY

		case GAME_STATE::STORY:
			CStory::GetInstance().Draw();
			break;


			// STAGE
		case GAME_STATE::STAGE:
			CStage::GetInstance().Draw();
			break;
		}
	}

void CGamemain::Finalize(void)
{
}

void CGamemain::Menu(void)
{
	
		/* 選択中 */
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RIGHT))
		{
			//選択ボタンの変更
			m_Now_Select = (SELECT_BUTTON)(((int)m_Now_Select + 1) % (int)SELECT_BUTTON::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

		}

		else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LEFT))
		{
			//選択ボタンの変更
			m_Now_Select = (SELECT_BUTTON)((((int)m_Now_Select - 1) + (int)SELECT_BUTTON::MAX) % (int)SELECT_BUTTON::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

		}

		
	
}

void CGamemain::DrawMenu(void)
{
	vivid::DrawTexture("data\\t_bg.png", { 0,0 });
	vivid::DrawText(48, "menu", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xfffffffff);
	vivid::DrawTexture("data\\arrow.png", m_Finger_Position);

	for (int i = 0; i < (int)SELECT_BUTTON::MAX; i++)
	{
		m_Button_Position = vivid::Vector2(m_Button_x[i], m_Button_y);

		if (i == (int)m_Now_Select)
			vivid::DrawTexture(m_Button_Image[i], m_Button_Position, m_Select_Button_Color);
		else
			vivid::DrawTexture(m_Button_Image[i], m_Button_Position);
	}
}