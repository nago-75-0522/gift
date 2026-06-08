#pragma once
#include "vivid.h"
#include"../../map/forest_manager/forest/forest.h"
/* 主人公 */


class CProtagonist 
{
public:
	
	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);
	void SetChangePosition1();
	void SetChangePosition2();
	void SetChangePosition3();
	void SetChangePosition4();
	void SetBackPosition();
	void WaitCharacter();
	void MoveCharacter();
	void StopCharacter();
	void Controller();
	vivid::Vector2 GetCharaPos();
	static CProtagonist& GetInstance();	

private:
	CProtagonist(void);
	//コピーコンストラクタ
	CProtagonist(const CProtagonist& rhp) = delete;

	CProtagonist& operator=(const CProtagonist& rhp) = delete;

	~CProtagonist(void) = default;

	//定数
	static const int m_chara_width;
	static const int m_chara_height;
	static const int m_chara_move_time;
	static const float m_chara_move_speed;
	static const vivid::Vector2 m_tree_size;
	static const int m_yellow_nuts;

	//変数
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
	vivid::Vector2 m_CharaPos;
	vivid::Rect m_CharaRect ;
	vivid::Vector2 m_CharaSpeed;
	int m_CharaAnimeFrame ;
	int m_CharaAnimeTimer;
	int m_CharaMoveTimer;
};
