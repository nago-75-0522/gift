#pragma once
/* 白色のネックレス */
#include"vivid.h"

class CWhite_Necklace
{
public:
	CWhite_Necklace(void);
	~CWhite_Necklace(void) = default;

	void Initialize(void);

	void Draw(void);

private:
	static const vivid::Vector2 m_position;

	bool m_isHitFlag; //採ったかどうか
};