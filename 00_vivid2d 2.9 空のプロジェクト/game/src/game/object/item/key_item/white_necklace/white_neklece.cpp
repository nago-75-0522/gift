#include"white_necklece.h"

const vivid::Vector2 CWhite_Necklece::m_position = { 0.0f,0.0f };

void CWhite_Necklece::Draw(void)
{
	vivid::DrawTexture("data\\ball.png", m_position);
}