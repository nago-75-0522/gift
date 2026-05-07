#include"forth_peace.h"

const vivid::Vector2 CForth_Peace::m_position = { 0.0f,0.0f };

void CForth_Peace::Draw(void)
{
	vivid::DrawTexture("data\\parts4.png", m_position);
}
