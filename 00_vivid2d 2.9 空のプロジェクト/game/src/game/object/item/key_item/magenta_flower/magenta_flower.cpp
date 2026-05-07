#include"magenta_flower.h"

const vivid::Vector2 CMagenta_Flower::m_position = { 0.0f,0.0f };

void CMagenta_Flower::Initialize(void)
{
}

void CMagenta_Flower::Draw(void)
{
	vivid::DrawTexture("data\\magenta.png", m_position);
}
