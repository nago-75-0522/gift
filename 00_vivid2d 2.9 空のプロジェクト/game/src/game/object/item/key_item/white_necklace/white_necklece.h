#pragma once
/* 白色のネックレス */
#include"vivid.h"

class CWhite_Necklece
{
public:
	CWhite_Necklece(void) = default;
	~CWhite_Necklece(void) = default;

	void Initialize(void);

	void Draw(void);

private:
	static const vivid::Vector2 m_position;

	bool m_isHitFlag;
};