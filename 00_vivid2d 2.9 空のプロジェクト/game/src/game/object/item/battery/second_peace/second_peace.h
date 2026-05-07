//電池作る２つ目のパーツ
#pragma once
#include"vivid.h"

class CSecond_Peace
{
public:
	CSecond_Peace(void) = default;
	~CSecond_Peace(void) = default;

	void Draw(void);
private:
	static const vivid::Vector2 m_position;
};

