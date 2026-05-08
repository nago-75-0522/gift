/* 主人公 */
#include"protagonist.h"
#include"../../map/forest/forest.h"

CForest forest;

const int CProtagonist::m_chara_height=48;
const int CProtagonist::m_chara_width=48;
const int CProtagonist::m_chara_move_time = 12;

//移動速度（道のり/時間）
const float CProtagonist::m_chara_move_speed = (float)forest.GetMapChipSize() / (float) m_chara_move_time;
CProtagonist::CProtagonist(void)
	:  m_CharaPos{0.0f,0.0f}
	,  m_CharaRect{0,0,m_chara_width,m_chara_height}
	,  m_CharaSpeed{0.0f,0.0f}
	,  m_CharaAnimeFrame(0)
	,  m_CharaAnimeTimer(0)
	,  m_CharaMoveTimer(0)
{
}

void CProtagonist::Initialize(void)
{
	m_CharaPos = forest.GetStartPos();
}

void CProtagonist::Update(void)
{
	switch (m_Chara_State)
	{
	case CHARA_STATE::WAIT:
		WaitCharacter();
		break;
	case CHARA_STATE::MOVE:
		MoveCharacter();
		break;
	}

	//移動計算
	m_CharaPos.x += m_CharaSpeed.x;
	m_CharaPos.y += m_CharaSpeed.y;
}

void CProtagonist::Draw(void)
{
	m_CharaRect.left = m_CharaAnimeFrame * m_chara_width;
	m_CharaRect.right = m_CharaRect.left + m_chara_width;
	m_CharaRect.top = (int)m_Chara_Direction * m_chara_height;
	m_CharaRect.bottom = m_CharaRect.top + m_chara_height;

	vivid::DrawTexture("data\\Character.png", m_CharaPos, 0xffffffff, m_CharaRect);
	
}

void CProtagonist::Finalize(void)
{
}

void CProtagonist::WaitCharacter()
{
	namespace keyboard = vivid::keyboard;

	int x = (int)((m_CharaPos.x + 0.5f) / (float)forest.GetMapChipSize());
	int y = (int)((m_CharaPos.y + 0.5f) / (float)forest.GetMapChipSize());

		
			if (keyboard::Button(keyboard::KEY_ID::W))
			{
				m_Chara_Direction = CHARA_DIRECTION::UP;

				//自分のいるマス目から一つ上側を調べる。これがfalseなら進める。
				if (!forest.CheckWall(x, y - 1))
				{
					m_CharaSpeed.y = -m_chara_move_speed;
					m_Chara_State = CHARA_STATE::MOVE;
				}
			}
			else if (keyboard::Button(keyboard::KEY_ID::S))
			{
				m_Chara_Direction = CHARA_DIRECTION::DOWN;

				//自分のいるマス目から一つ下側を調べる。
				if (!forest.CheckWall(x, y + 1))
				{
					m_CharaSpeed.y = +m_chara_move_speed;
					m_Chara_State = CHARA_STATE::MOVE;
				}
			}
			else if (keyboard::Button(keyboard::KEY_ID::D))
			{
				m_Chara_Direction = CHARA_DIRECTION::RIGHT;

				//自分のいるマス目から一つ右側を調べる。
				if (!forest.CheckWall(x + 1, y))
				{
					m_CharaSpeed.x = +m_chara_move_speed;
					m_Chara_State = CHARA_STATE::MOVE;
				}
			}
			else if (keyboard::Button(keyboard::KEY_ID::A))
			{
				m_Chara_Direction = CHARA_DIRECTION::LEFT;

				//自分のいるマス目から一つ左側を調べる。
				if (!forest.CheckWall(x - 1, y))
				{
					m_CharaSpeed.x = -m_chara_move_speed;
					m_Chara_State = CHARA_STATE::MOVE;
				}
			}
		
}

void CProtagonist::MoveCharacter()
{
	//移動時間の計算
	if (++m_CharaMoveTimer >= m_chara_move_time)
	{
		m_CharaMoveTimer = 0;
		m_CharaSpeed.x = 0;
		m_CharaSpeed.y = 0;

		//時間が来たら待機状態に戻す
		m_Chara_State = CHARA_STATE::WAIT;

		return;
	}

	//アニメーションタイマーの更新
	if (++m_CharaAnimeTimer > 10)
	{
		m_CharaAnimeTimer = 0;
		//アニメーションフレームを更新
		++m_CharaAnimeFrame %= 3;
	}
}
