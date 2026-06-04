#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"
#include"stage/stage_manager.h"
#include"..\..\scene_manager.h"
#include"..\save\save.h"
//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート

//定数
const vivid::Vector2 CGamemain::m_BG_Position(0.0f, 0.0f);
const int CGamemain::m_Button_x[]{ 230, 810 };
const int CGamemain::m_Button_y(vivid::WINDOW_HEIGHT / 2);
const int CGamemain::m_Finger_Width(230);
const std::string CGamemain::m_Button_Image[] = { "data\\first.png","data\\second.png" };
const unsigned int CGamemain::m_Select_Button_Color(0xffffffff);


CGamemain& CGamemain::GetInstance()
{
	static CGamemain instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

//コンストラクタ
CGamemain::CGamemain()
	:m_Now_GameState (GAME_STATE::MENU)  //最初にメニューを表示
{
}


//親クラスの作成
//初期化
void CGamemain::Initialize(void)
{
	m_Now_Select = SELECT_BUTTON::START;

	m_Button_Position = vivid::Vector2::ZERO;//位置
	//ｘは配列に合わせるため
	m_Finger_Position.x = m_Button_x[(int)m_Now_Select] - m_Finger_Width;//指のｘ座標の初期化
	//矢印yは選択中ボタンの高さと変わらないため
	m_Finger_Position.y = m_Button_y;									//指のy座標の初期化

	vivid::Vector2 m_Stic = vivid::controller::GetAnalogStickLeft(vivid::controller::DEVICE_ID::PLAYER1);//スティック

}



//更新
void CGamemain::Update(void)
{
	switch (m_Now_GameState)
	{
		//MENU
	case GAME_STATE::MENU:
		Menu();

		/* キーボード用 */
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
		{
			if(m_Now_Select == SELECT_BUTTON::START)
			{
				CStory::GetInstance().ChangeStory(STORY_ID::OPNING);
				m_Now_GameState = GAME_STATE::STORY;//ストーリーモードにする
			}

			else
			{
				//続きからの場合の処理(セーブファイルに飛ぶようにする)
				CSceneManager::GetInstance().Change(SCENE_ID::SAVE);
				m_Now_GameState = GAME_STATE::SAVE;//セーブモードにする
			}
		}

		/* コントローラ用 */
		if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
		{
			if (m_Now_Select == SELECT_BUTTON::START)
			{
				CStory::GetInstance().ChangeStory(STORY_ID::OPNING);
				m_Now_GameState = GAME_STATE::STORY;//ストーリーモードにする
			}

			else
			{
				//続きからの場合の処理(セーブファイルに飛ぶようにする)
				CSceneManager::GetInstance().Change(SCENE_ID::SAVE);
				m_Now_GameState = GAME_STATE::SAVE;//セーブモードにする

			}
		}
		break;



		// STORY
	case GAME_STATE::STORY:
		CStory::GetInstance().Update();

		//Story側がStageに行きたいときにtrueにする
		if (CStory::GetInstance().m_RequestStage == true)
		{
			CStory::GetInstance().m_RequestStage = false;
			m_Now_GameState = GAME_STATE::STAGE;//ステージモード
		}

		break;


		//STAGE
	case GAME_STATE::STAGE:
		CStage::GetInstance().Update();
		break;


	case GAME_STATE::SAVE:
		CSave::GetInstance().Update();
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

		//SAVE
	case GAME_STATE::SAVE:
		CSave::GetInstance().Draw();
		break;

	}
}

void CGamemain::Finalize(void)
{
}

void CGamemain::Menu(void)
{
	/* コントローラーの実装 */
	//デッドゾーンの設定
	const float DEAD_ZONE = 0.7f;

	//前フレームのスティックXを保持
	static float prev_stick_x = 0.0f;

	//左スティック入力取得
	vivid::Vector2 m_stick = vivid::controller::GetAnalogStickLeft(vivid::controller::DEVICE_ID::PLAYER1);

	//右に倒した瞬間（前フレームはデッドゾーン内、現在のフレームは超えた）
	if (prev_stick_x <= DEAD_ZONE && m_stick.x > DEAD_ZONE)
	{
		m_Now_Select = (SELECT_BUTTON)(((int)m_Now_Select + 1) % (int)SELECT_BUTTON::MAX);
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);
	}

	// 左に倒した瞬間
	else if (prev_stick_x >= -DEAD_ZONE && m_stick.x < -DEAD_ZONE)
	{
		m_Now_Select = (SELECT_BUTTON)((((int)m_Now_Select - 1) + (int)SELECT_BUTTON::MAX) % (int)SELECT_BUTTON::MAX);
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);
	}

	// 現在の値を保存
	prev_stick_x = m_stick.x;


	/* 十字キー実装 */
	if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1,vivid::controller::BUTTON_ID::RIGHT))
	{
		//選択ボタンの変更
		m_Now_Select = (SELECT_BUTTON)(((int)m_Now_Select + 1) % (int)SELECT_BUTTON::MAX);

		//指の位置変更
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

	}

	else if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1,vivid::controller::BUTTON_ID::LEFT))
	{
		//選択ボタンの変更
		m_Now_Select = (SELECT_BUTTON)((((int)m_Now_Select - 1) + (int)SELECT_BUTTON::MAX) % (int)SELECT_BUTTON::MAX);

		//指の位置変更
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);
		
	}
	


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
	vivid::DrawText(48, "menu", { vivid::WINDOW_WIDTH / 2 - 100,0 }, 0xffffffff);
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

//セーブからステージにセットする用
void CGamemain::SetGameState(GAME_STATE state)
{
	m_Now_GameState = state;
}