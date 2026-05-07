//電池作る1つ目のパーツ
#pragma once
#include"vivid.h"

class CFirst_Peace
{
public:
	CFirst_Peace(void) = default;
	~CFirst_Peace(void) = default;

	void Draw(void);
private:
	static const vivid::Vector2 m_position;
};
