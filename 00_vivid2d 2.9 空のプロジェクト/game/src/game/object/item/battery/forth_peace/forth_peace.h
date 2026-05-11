//電池作る４つ目のパーツ
#pragma once
#include"vivid.h"

class CForth_Peace
{
public:
	CForth_Peace(void);
	~CForth_Peace(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	bool m_isHitFlag;

	static const vivid::Vector2 m_position;
};
