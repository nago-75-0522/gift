#include"first_peace.h"

const vivid::Vector2 CFirst_Peace::m_position = { 0.0f,0.0f };

void CFirst_Peace::Draw(void)
{
	vivid::DrawTexture("data\\parts1.png", m_position);
}