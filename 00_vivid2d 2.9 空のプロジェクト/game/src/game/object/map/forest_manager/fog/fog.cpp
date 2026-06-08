#include "fog.h"
#include"../../../character/protagonist/protagonist.h"
const int CFog::m_set_fog_interval = 60 * 2;
const int CFog::m_set_fog_timer = 60 * 10;
const int CFog::m_fog_fade_speed = 1;

CFog::CFog()
	:m_Fog_Pos(0.0f, 0.0f)
	, m_Fog_Speed(0.0f, 0.0f)
	, m_Fog_Timer(0)
	,m_Fog_Color(0x00ffffff)
	,m_Fog_Interval(0)
	,m_Fog_State(FOG_STATE::DARK)
{
}

void CFog::Initialize()
{	
	m_Fog_Timer = m_set_fog_timer;
	m_Fog_Interval = m_set_fog_interval;
	m_Fog_Pos = { 0.0f, 0.0f };
	m_Fog_Color = (0x00ffffff);
	m_Fog_State = (FOG_STATE::DARK);	
}

void CFog::Update()
{	
	//アルファ値(透明度)の計算
	if (m_Fog_State == FOG_STATE::DARK)
	{
		if (--m_Fog_Interval <= 0)
		{
			int a = (m_Fog_Color & 0xff000000) >> 24;

			a += m_fog_fade_speed;


			m_Fog_Color = (a << 24) | (m_Fog_Color & 0x00ffffff);
			if (m_Fog_Color >= 0xffffffff)
			{
				m_Fog_Timer = m_set_fog_timer;
				m_Fog_State = FOG_STATE::LIGHT;
			}
		}
	}
	
		//アルファ値(透明度)の計算
	if (--m_Fog_Timer <= 0&& m_Fog_State == FOG_STATE::LIGHT)
	{
		m_Fog_Interval = m_set_fog_interval;
		int a = (m_Fog_Color & 0xff000000) >> 24;

		a -= m_fog_fade_speed;//α値を減らす

		m_Fog_Color = (a << 24) | (m_Fog_Color & 0x00ffffff);
		if (m_Fog_Color <= 0x00ffffff)
		{
			m_Fog_State = FOG_STATE::DARK;
		}
	}
	
}

void CFog::Draw()
{
	    vivid::DrawTexture("data\\forest\\fog.png", m_Fog_Pos, m_Fog_Color);
		vivid::DrawTexture("data\\forest\\shadow.png", CProtagonist::GetInstance().GetCharaPos(), m_Fog_Color);
	
}

CFog& CFog::GetInstance()
{
	
	static CFog instance;
	return instance;//インスタンスを返す
	
}




