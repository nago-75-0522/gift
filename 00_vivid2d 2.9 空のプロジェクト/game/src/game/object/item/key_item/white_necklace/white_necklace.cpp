#include"white_necklace.h"

const vivid::Vector2 CWhite_Necklace::m_position = { 0.0f,0.0f };

CWhite_Necklace::CWhite_Necklace(void)
	:m_isHitFlag(false)
{
}

void CWhite_Necklace::Initialize(void)
{
	m_isHitFlag = false;
}

void CWhite_Necklace::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\ball.png", m_position);
}