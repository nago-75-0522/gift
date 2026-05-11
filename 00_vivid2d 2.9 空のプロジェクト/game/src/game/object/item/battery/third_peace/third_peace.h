//電池作る３つ目のパーツ
#pragma once
#include"vivid.h"

class CThird_Peace
{
public:
	CThird_Peace(void);
	~CThird_Peace(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	bool m_isHitFlag;

	static const vivid::Vector2 m_position;
};
