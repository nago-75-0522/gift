//霧
#pragma once
#include"vivid.h"
class CFog
{

public:
	
	void Initialize();
	void Update();
	void Draw();
	static CFog& GetInstance();
	
private:
	CFog(void);
	//コピーコンストラクタ
	CFog(const CFog& rhp) = delete;

	CFog& operator=(const CFog& rhp) = delete;

	~CFog(void) = default;
	//定数
	static const int m_set_fog_interval;
	static const int m_set_fog_timer;
	static const int m_fog_fade_speed;
	
	
	//変数

	enum class FOG_STATE
	{
		WAIT,
		LIGHT,
		DARK,
	};
	FOG_STATE m_Fog_State;

	vivid::Vector2 m_Fog_Pos;
	vivid::Vector2 m_Fog_Speed;
	int m_Fog_Timer;
	int m_Fog_Interval;
	unsigned int m_Fog_Color;
};