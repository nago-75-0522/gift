#include"first_peace.h"

const vivid::Vector2 CFirst_Peace::m_position = { 0.0f,0.0f };

CFirst_Peace::CFirst_Peace(void)
	:m_isHitFlag(false)
{
}

void CFirst_Peace::Initialize(void)
{
	m_isHitFlag = false;
}

void CFirst_Peace::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\parts1.png", m_position);
}