//電池作る２つ目のパーツ
#pragma once
#include"vivid.h"

class CSecond_Peace
{
public:
	CSecond_Peace(void);
	~CSecond_Peace(void) = default;

	void Initialze(void);

	void Draw(void);
private:
	bool m_isHitFlag; //とったかどうか

	static const vivid::Vector2 m_position;
};

