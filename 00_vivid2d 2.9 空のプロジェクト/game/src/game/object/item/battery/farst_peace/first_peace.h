//電池作る1つ目のパーツ
#pragma once
#include"vivid.h"

class CFirst_Peace
{
public:
	CFirst_Peace(void);
	~CFirst_Peace(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	static const vivid::Vector2 m_position;

	bool m_isHitFlag;
};
