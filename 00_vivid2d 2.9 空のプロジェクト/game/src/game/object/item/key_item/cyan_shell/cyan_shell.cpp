#include"cyan_shell.h"

const vivid::Vector2 CCyan_Shell::m_position = { 0.0f,0.0f };

CCyan_Shell::CCyan_Shell(void)
	:m_isHitFlag(false)
{
}

void CCyan_Shell::Initialize(void)
{
	m_isHitFlag = false;
}

void CCyan_Shell::Draw(void)
{
	if (m_isHitFlag == true)
		return;

	vivid::DrawTexture("data\\cyan_item.png", m_position);
}
