#pragma once
#include "vivid.h"
/* 主人公 */


class CProtagonist 
{
public:
	CProtagonist(void);
	~CProtagonist(void) = default;

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);
	void WaitCharacter();
	void MoveCharacter();
	vivid::Vector2 GetCharaPos();
	static CProtagonist& GetInstance();
private:

	enum class CHARA_DIRECTION
	{
		DOWN,
		LEFT,
		RIGHT,
		UP,
	};
	CHARA_DIRECTION m_Chara_Direction;

	enum CHARA_STATE
	{
		WAIT,
		MOVE,
	};
	CHARA_STATE m_Chara_State;


	//定数
	static const int m_chara_width;
	static const int m_chara_height;
	static const int m_chara_move_time;
	static const float m_chara_move_speed;

	//変数
	vivid::Vector2 m_CharaPos;
	vivid::Rect m_CharaRect ;
	vivid::Vector2 m_CharaSpeed;
	int m_CharaAnimeFrame ;
	int m_CharaAnimeTimer;
	int m_CharaMoveTimer;
};
