#pragma once
/* 黄色の木の実 */
#include"vivid.h"

class CYellow_Nuts
{
public:
	CYellow_Nuts(void);
	~CYellow_Nuts(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	static const vivid::Vector2 m_position;
	
	bool m_isHitFlag; //採ったかどうか
};