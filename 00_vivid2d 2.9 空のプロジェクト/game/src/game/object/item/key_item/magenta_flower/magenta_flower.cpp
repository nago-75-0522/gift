#include"magenta_flower.h"

const vivid::Vector2 CMagenta_Flower::m_position = { 0.0f,0.0f };

CMagenta_Flower::CMagenta_Flower(void)
	:m_isHitFlag(false)
{
}

void CMagenta_Flower::Initialize(void)
{
	m_isHitFlag = false;
}

void CMagenta_Flower::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\magenta.png", m_position);
}
