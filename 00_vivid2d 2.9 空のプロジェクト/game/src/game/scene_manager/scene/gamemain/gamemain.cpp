#include"gamemain.h"
#include"vivid.h"
#include"story/story_manager.h"


//定数
const vivid::Vector2 CGamemain::m_BG_Position(0.0f, 0.0f);
const int CGamemain::m_Button_x[]{ 230, 810};
const int CGamemain::m_Button_y(vivid::WINDOW_HEIGHT/2);
const int CGamemain::m_Finger_Width(230);
const std::string CGamemain::m_Button_Image[] = { "data\\first.png","data\\second.png"};
const unsigned int CGamemain::m_Select_Button_Color(0xffffffff);




//はじめからか続きからを選択
//初めからの場合はプロローグ　続きからならセーブしているステージからスタート
//初期化
void CGamemain::Initialize(void)
{
	
	CStory::GetInstance().Initialize();//初期化呼び出し
	m_Button_Position = vivid::Vector2::ZERO;//位置
	//ｘは配列に合わせるため
	m_Finger_Position.x = m_Button_x[(int)m_now_select] - m_Finger_Width;//指のｘ座標の初期化
	//矢印yは選択中ボタンの高さと変わらないため
	m_Finger_Position.y = m_Button_y;									//指のy座標の初期化
	m_now_select = (SELECT_BUTTON::START);

}

//更新
void CGamemain::Update(void)
{
	/* 選択中 */
	if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::RIGHT))
	{
		//選択ボタンの変更
		m_now_select = (SELECT_BUTTON)(((int)m_now_select + 1) % (int)SELECT_BUTTON::MAX);

		//指の位置変更
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_now_select] - m_Finger_Width, m_Button_y);

	}

	else if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::LEFT))
	{
		//選択ボタンの変更
		m_now_select = (SELECT_BUTTON)((((int)m_now_select - 1) + (int)SELECT_BUTTON::MAX) % (int)SELECT_BUTTON::MAX);

		//指の位置変更
		m_Finger_Position = vivid::Vector2(m_Button_x[(int)m_now_select] - m_Finger_Width, m_Button_y);

	}


	/* 選択後 */
	switch (m_now_select)
	{
		//初めからの場合
	case CGamemain::SELECT_BUTTON::START:

		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		{
			CStory::GetInstance().Change(STORY_ID::OPNING);

		}

		break;

		//続きからの場合
	case CGamemain::SELECT_BUTTON::CONTINUED:

		if (vivid::keyboard::Trigger(vivid::keyboard::KEY_ID::Z))
		{
			CStory::GetInstance().Update();//更新呼び出し
		}

		

		break;

	case CGamemain::SELECT_BUTTON::MAX:
		//何もしない
		break;
	default:
		break;
	}
	
	

}

//描画
void CGamemain::Draw(void)
{
	//CStory::GetInstance().Draw();//描画呼び出し
	vivid::DrawTexture("data\\t_bg.png", { 0,0 });
	vivid::DrawText(48, "menu", { vivid::WINDOW_WIDTH / 2 -100,0 }, 0xfffffffff);

	vivid::DrawTexture("data\\arrow.png", m_Finger_Position);//選択中ボタン
	for (int i = 0; i < (int)SELECT_BUTTON::MAX; i++)
	{
		//ボタン座標を入れるs
		m_Button_Position = vivid::Vector2(m_Button_x[i], m_Button_y);

		//ボタンの描画
		if (i == (int)m_now_select)
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

//解放
void CGamemain::Finalize(void)
{
	CStory::GetInstance().Finalize();//解放呼び出し

}

