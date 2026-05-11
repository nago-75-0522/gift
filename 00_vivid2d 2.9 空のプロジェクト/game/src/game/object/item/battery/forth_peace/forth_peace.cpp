#include"forth_peace.h"

const vivid::Vector2 CForth_Peace::m_position = { 0.0f,0.0f };

CForth_Peace::CForth_Peace(void)
	:m_isHitFlag(false)
{
}

void CForth_Peace::Initialize(void)
{
	m_isHitFlag = false;
}

void CForth_Peace::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\parts4.png", m_position);
}
