#include "second_peace.h"

const vivid::Vector2 CSecond_Peace::m_position = { 0.0f,0.0f };

CSecond_Peace::CSecond_Peace(void)
	:m_isHitFlag(false)
{
}

void CSecond_Peace::Initialze(void)
{
	m_isHitFlag = false;
}

void CSecond_Peace::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\parts2.png", m_position);
}
