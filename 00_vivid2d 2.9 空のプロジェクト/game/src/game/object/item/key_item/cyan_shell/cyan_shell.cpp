#include"cyan_shell.h"

const vivid::Vector2 CCyan_Shell::m_position = { 0.0f,0.0f };

CCyan_Shell::CCyan_Shell(void)
	:m_isHitFlag(false)
{
}

void CCyan_Shell::Initialize(void)
{
}

void CCyan_Shell::Draw(void)
{
	vivid::DrawTexture("data\\cyan_item.png", m_position);
}
