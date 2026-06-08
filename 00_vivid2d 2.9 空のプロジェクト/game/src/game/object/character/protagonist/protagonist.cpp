/* 主人公 */
#include"protagonist.h"
#include"../../map/forest_manager/forest/forest.h"
#include"../../map/forest_manager/fallen_tree/fallen_tree.h"
#include"../../map/forest_manager/forest_manager.h"

const int CProtagonist::m_chara_height=48;
const int CProtagonist::m_chara_width=48;
const int CProtagonist::m_chara_move_time = 12;
const vivid::Vector2 CProtagonist::m_tree_size = { 64.0f,128.0f };
const int CProtagonist::m_yellow_nuts = 192;

static bool CheckCollision(
	vivid::Vector2 a, float aw, float ah,   
	vivid::Vector2 b, float bw, float bh)   
{
	return (

		a.x < b.x + bw &&
		a.x + aw > b.x &&
		a.y < b.y + bh &&
		a.y + ah > b.y
		);

	// X軸・Y軸の両方で重なっていれば衝突。
}

//移動速度（道のり/時間）
const float CProtagonist::m_chara_move_speed = (float)CForest::GetInstance().GetMapChipSize() / (float) m_chara_move_time;
CProtagonist::CProtagonist(void)
	:  m_CharaPos{0.0f,0.0f}
	,  m_CharaRect{0,0,m_chara_width,m_chara_height}
	,  m_CharaSpeed{0.0f,0.0f}
	,  m_CharaAnimeFrame(0)
	,  m_CharaAnimeTimer(0)
	,  m_CharaMoveTimer(0)
{
}

//初期化
void CProtagonist::Initialize(void)
{
	m_CharaPos.x = CForest::GetInstance().GetBack().x;
	m_CharaPos.y = CForest::GetInstance().GetBack().y;
}


//
//マップ2-->1に戻った時などにキャラの位置を設定する
//
void CProtagonist::SetChangePosition1()
{
	m_CharaPos = CForest::GetInstance().GetChange1();
}

void CProtagonist::SetChangePosition2()
{
	m_CharaPos = CForest::GetInstance().GetChange2();
}

void CProtagonist::SetChangePosition3()
{
	m_CharaPos = CForest::GetInstance().GetChange3();
}

void CProtagonist::SetChangePosition4()
{
	m_CharaPos = CForest::GetInstance().GetChange4();
}


//
//マップ切り替えの時にキャラの位置を出口に設定
//

void CProtagonist::SetBackPosition()
{
	m_CharaPos.x = CForest::GetInstance().GetBack().x;
	m_CharaPos.y = CForest::GetInstance().GetBack().y;
}


//更新
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

	if (CheckCollision(
		CFallen_Tree::GetInstance().GetTreePos1(),m_tree_size.x,m_tree_size.y ,
		m_CharaPos, m_chara_width, m_chara_height) && CForest_Manager::GetInstance().GetID() == FOREST_ID::FOREST4)
	{
		m_CharaPos.x = 0;
	}
	else if (CheckCollision(
		CFallen_Tree::GetInstance().GetTreePos2(), m_tree_size.x, m_tree_size.y,
		m_CharaPos, m_chara_width, m_chara_height) && CForest_Manager::GetInstance().GetID() == FOREST_ID::FOREST4) 
	{
		m_CharaPos.x = 0;
	}
	else if (CheckCollision(
		CFallen_Tree::GetInstance().GetTreePos3(), m_tree_size.x, m_tree_size.y,
		m_CharaPos, m_chara_width, m_chara_height)&&CForest_Manager::GetInstance().GetID()==FOREST_ID::FOREST4)
	{
		m_CharaPos.x = 0;
	}
	
}

//描画
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
	namespace controller = vivid::controller;

	// スティック入力取得
	vivid::Vector2 stick = controller::GetAnalogStickLeft(controller::DEVICE_ID::PLAYER1);

	const float DEAD_ZONE = 0.5f;
	int x = (int)((m_CharaPos.x + 0.5f) / (float)CForest::GetInstance().GetMapChipSize());
	int y = (int)((m_CharaPos.y + 0.5f) / (float)CForest::GetInstance().GetMapChipSize());

		
	if (Button(keyboard::KEY_ID::W) || stick.y < -DEAD_ZONE)
	{
		m_Chara_Direction = CHARA_DIRECTION::UP;

		//自分のいるマス目から一つ上側を調べる。これがfalseなら進める。
		if (!CForest::GetInstance().CheckWall(x, y - 1)&& !CForest::GetInstance().CheckInvisivleWall(x , y - 1))
		{
			m_CharaSpeed.y = -m_chara_move_speed;
			m_Chara_State = CHARA_STATE::MOVE;
		}
		

	}
	else if (Button(keyboard::KEY_ID::S) || stick.y > DEAD_ZONE)
	{
		m_Chara_Direction = CHARA_DIRECTION::DOWN;

		//自分のいるマス目から一つ下側を調べる。
		if (!CForest::GetInstance().CheckWall(x, y + 1) && !CForest::GetInstance().CheckInvisivleWall(x, y + 1))
		{
			m_CharaSpeed.y = +m_chara_move_speed;
			m_Chara_State = CHARA_STATE::MOVE;
		}
		
	}
	else if (Button(keyboard::KEY_ID::D) || stick.x > DEAD_ZONE)
	{
		m_Chara_Direction = CHARA_DIRECTION::RIGHT;

		if (!CForest::GetInstance().CheckWall(x + 1, y) && !CForest::GetInstance().CheckInvisivleWall(x + 1, y))
		{
			m_CharaSpeed.x = +m_chara_move_speed;
			m_Chara_State = CHARA_STATE::MOVE;
		}
		
	}
	else if (Button(keyboard::KEY_ID::A) || stick.x < -DEAD_ZONE)
	{
		m_Chara_Direction = CHARA_DIRECTION::LEFT;

		//自分のいるマス目から一つ左側を調べる。
		if (!CForest::GetInstance().CheckWall(x - 1, y) && !CForest::GetInstance().CheckInvisivleWall(x - 1, y))
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
void CProtagonist::StopCharacter()
{
	m_CharaSpeed.x = 0;
	m_CharaSpeed.y = 0;
	m_CharaMoveTimer = 0;
	m_Chara_State = CHARA_STATE::WAIT;
}

void CProtagonist::Controller()
{

}

vivid::Vector2 CProtagonist::GetCharaPos()
{
	return m_CharaPos;
}

CProtagonist& CProtagonist::GetInstance()
{
	static CProtagonist instance;
	return instance;
}


