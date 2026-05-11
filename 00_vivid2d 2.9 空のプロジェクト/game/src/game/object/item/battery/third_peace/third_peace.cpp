#include"third_peace.h"

const vivid::Vector2 CThird_Peace::m_position = { 0.0f,0.0f };

CThird_Peace::CThird_Peace(void)
	:m_isHitFlag(false)
{
}

void CThird_Peace::Initialize(void)
{
	m_isHitFlag = false;
}

void CThird_Peace::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\parts3.png", m_position);
}
