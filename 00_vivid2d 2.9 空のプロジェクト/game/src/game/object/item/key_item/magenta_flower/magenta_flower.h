#pragma once
/* マゼンタ色の花 */
#include"vivid.h"

class CMagenta_Flower
{
public:
	CMagenta_Flower(void) = default;
	~CMagenta_Flower(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	static const vivid::Vector2 m_position;

	bool m_isHitFlag;
};