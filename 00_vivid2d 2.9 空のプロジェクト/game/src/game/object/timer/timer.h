#pragma once
#include"vivid.h"

class CTimer
{
public: 
	CTimer(void);
	~CTimer(void) = default;
	void Initialize(void);
	void Update(void);
	void Draw(void);

	
	static CTimer& GetInstanse(void);

private:
	//定数
  static const int m_play_time;

	//変数
	vivid::Vector2 m_Timer_pos;
	vivid::Rect m_Timer_rect;
	vivid::Vector2 m_Timer_anchor;
	vivid::Vector2 m_Timer_scale;
	unsigned int m_Timer_color;
	int m_Play_timer;
	int m_Timer_angle;

	static const float a;



};