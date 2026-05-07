#include "second_peace.h"

const vivid::Vector2 CSecond_Peace::m_position = { 0.0f,0.0f };

void CSecond_Peace::Draw(void)
{
	vivid::DrawTexture("data\\parts2.png", m_position);
}
