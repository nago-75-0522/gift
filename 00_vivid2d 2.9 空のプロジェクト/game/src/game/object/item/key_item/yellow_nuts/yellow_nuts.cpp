#include"yellow_nuts.h"

const vivid::Vector2 CYellow_Nuts::m_position = { 0.0f,0.0f };

CYellow_Nuts::CYellow_Nuts(void)
	:m_isHitFlag(false)
{
}

void CYellow_Nuts::Initialize(void)
{
	m_isHitFlag = false;
}

void CYellow_Nuts::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\yellow.png", m_position);
}
