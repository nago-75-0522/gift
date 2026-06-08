
#include "save.h"
#include"..\gamemain\stage\stage_manager.h"
#include"..\gamemain\gamemain.h"
#include"..\..\scene_manager.h"
#include"vivid.h"

//save とりあえずステージを選んで飛べるようにする

//定数
const vivid::Vector2 CSave::m_BG_Position(0.0f, 0.0f);
const int CSave::m_Button_x[]{ 116,332, 548, 764 ,980 };
const int CSave::m_Button_y(vivid::WINDOW_HEIGHT / 2);
const int CSave::m_Finger_Width(100);
const std::string CSave::m_Button_Image[] =
{ "data\\stage1.png","data\\stage2.png","data\\stage3.png","data\\stage4.png","data\\stage5.png"};

const unsigned int CSave::m_Select_Button_Color(0xff0000cd);

CSave& CSave::GetInstance()
{
	static CSave instance;//インスタンスの作成
	return instance;//インスタンスを返す

}


/* 初期化 */
void CSave::Initialize(void)
{
	m_Now_Select = STAGE_ID::STAGE1;
	//m_Now_Save_State = SAVE_STATE::SAVE;

	m_Button_Position = vivid::Vector2::ZERO;//位置
	//ｘは配列に合わせるため
	m_Finger_Position.x = m_Button_x[(int)m_Now_Select] - m_Finger_Width;//指のｘ座標の初期化
	//矢印yは選択中ボタンの高さと変わらないため
	m_Finger_Position.y = m_Button_y;									//指のy座標の初期化

	vivid::Vector2 m_Stick = vivid::controller::GetAnalogStickLeft(vivid::controller::DEVICE_ID::PLAYER1);//スティック

}
/* 更新 */
void CSave::Update(void)
{	
	//選択の呼び出し
	SaveSelect();

	// SPACE または B で決定
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE) ||
		vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
	{
		
		//GameMain に「今はステージモード」と伝える
		CGamemain::GetInstance().SetGameState(CGamemain::GAME_STATE::STAGE);

		//STAGE シーンへ遷移（ここが最重要）
		CSceneManager::GetInstance().Change(SCENE_ID::STAGE);
	}
/*
		switch (m_Now_Select)
		{
		case STAGE_ID::STAGE1:
			
			break;

		case STAGE_ID::STAGE2:
		
			break;
		case STAGE_ID::STAGE3:
			CStage::GetInstance().ChangeStage(STAGE_ID::STAGE3);

			break;
		case STAGE_ID::STAGE4:
			CStage::GetInstance().ChangeStage(STAGE_ID::STAGE4);

			break;
		case STAGE_ID::STAGE5:
			CStage::GetInstance().ChangeStage(STAGE_ID::STAGE5);

			break;
		case STAGE_ID::MAX:
			break;
		default:
			break;
		}
	}

		if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::B))
		{
			switch (m_Now_Select)
			{
			case STAGE_ID::STAGE1:
				CStage::GetInstance().ChangeStage(STAGE_ID::STAGE1);


				if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::SPACE))
				{
					// ① 選んだステージをセット
					CStage::GetInstance().ChangeStage(m_Now_Select);

					// ② GameMain に「今はステージモード」と伝える
					CGamemain::GetInstance().SetGameState(CGamemain::GAME_STATE::STAGE);

					// ③ GameMain シーンへ戻る
					CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);
				}

				break;

			case STAGE_ID::STAGE2:
				CStage::GetInstance().ChangeStage(STAGE_ID::STAGE2);

				break;
			case STAGE_ID::STAGE3:
				CStage::GetInstance().ChangeStage(STAGE_ID::STAGE3);

				break;
			case STAGE_ID::STAGE4:
				CStage::GetInstance().ChangeStage(STAGE_ID::STAGE4);

				break;
			case STAGE_ID::STAGE5:
				CStage::GetInstance().ChangeStage(STAGE_ID::STAGE5);

				break;
			case STAGE_ID::MAX:
				break;
			default:
				break;
			}
		}
		*/

		/* 前の画面に戻る */
		if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::A))
		{
			CSceneManager::GetInstance().Change(SCENE_ID::GAMEMAIN);
		}
	
}

/* 描画 */
void CSave::Draw(void)
{
	vivid::DrawText(48, "save", { vivid::WINDOW_WIDTH / 2 - 10,0 });
	//vivid::DrawTexture("data\\arrow.png", m_Finger_Position);

	for (int i = 0; i < (int)STAGE_ID::MAX; i++)
	{
		//ボタン座標を入れる
		m_Button_Position = vivid::Vector2(m_Button_x[i], m_Button_y);

		//ボタンの描画

		if (i == (int)m_Now_Select)
		{
			//選択しているボタンを灰色にする
			vivid::DrawTexture(m_Button_Image[i], m_Button_Position, m_Select_Button_Color);
		}
		else
		{
			vivid::DrawTexture(m_Button_Image[i], m_Button_Position);
		}
	}
}

void CSave::Finalize(void)
{
}

/* セーブ画面中の処理 */
void CSave::SaveSelect(void)
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
			m_Now_Select = (STAGE_ID)(((int)m_Now_Select + 1) % (int)STAGE_ID::MAX);
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);
		}

		// 左に倒した瞬間
		else if (prev_stick_x >= -DEAD_ZONE && m_stick.x < -DEAD_ZONE)
		{
			m_Now_Select = (STAGE_ID)((((int)m_Now_Select - 1) + (int)STAGE_ID::MAX) % (int)STAGE_ID::MAX);
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);
		}

		// 現在の値を保存
		prev_stick_x = m_stick.x;


		/* 十字キー実装 */
		if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::RIGHT))
		{
			//選択ボタンの変更
			m_Now_Select = (STAGE_ID)(((int)m_Now_Select + 1) % (int)STAGE_ID::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

		}

		else if (vivid::controller::Trigger(vivid::controller::DEVICE_ID::PLAYER1, vivid::controller::BUTTON_ID::LEFT))
		{
			//選択ボタンの変更
			m_Now_Select = (STAGE_ID)((((int)m_Now_Select - 1) + (int)STAGE_ID::MAX) % (int)STAGE_ID::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

		}



		/* 選択中 */
		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RIGHT))
		{
			//選択ボタンの変更
			m_Now_Select = (STAGE_ID)(((int)m_Now_Select + 1) % (int)STAGE_ID::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);

		}

		else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LEFT))
		{
			//選択ボタンの変更
			m_Now_Select = (STAGE_ID)((((int)m_Now_Select - 1) + (int)STAGE_ID::MAX) % (int)STAGE_ID::MAX);

			//指の位置変更
			m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_Now_Select] - m_Finger_Width, m_Button_y);


		}
}
