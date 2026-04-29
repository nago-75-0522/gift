#include"timer.h"

const int CTimer::m_play_time = 10 * 60;
const float CTimer::a = 1 / m_play_time;

CTimer::CTimer()
	:m_Timer_pos{500.0f,500.0f}
	,m_Timer_rect{0,0,180,20}
	, m_Timer_anchor{0.0f,0.0f}
	,m_Timer_scale{1.0f,1.0f}
	,m_Play_timer{0}
	,m_Timer_color{0xffffffff}
, m_Timer_angle{ 0 }

{
}

void CTimer::Initialize()
{
	m_Play_timer = m_play_time;
}

void CTimer::Update()
{
	if (m_Play_timer > 0)
	{
		--m_Play_timer;

		// 残り時間の割合（0.0 ～ 1.0）
		m_Timer_scale.x = (float)m_Play_timer / (float)m_play_time;
	}
}


void CTimer::Draw()
{
	vivid::DrawTexture("data/timerber.png", m_Timer_pos, m_Timer_color
		, m_Timer_rect,m_Timer_anchor, m_Timer_scale);

	vivid::DrawTexture("data/timerflame.png", m_Timer_pos, m_Timer_color);
}

CTimer& CTimer::GetInstanse(void)
{
	// TODO: return ステートメントをここに挿入します
	static CTimer instance;
	return instance;
}
