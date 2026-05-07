//電池作る４つ目のパーツ
#pragma once
#include"vivid.h"

class CForth_Peace
{
public:
	CForth_Peace(void) = default;
	~CForth_Peace(void) = default;

	void Draw(void);
private:
	static const vivid::Vector2 m_position;
};
