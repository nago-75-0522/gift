#include"yellow_nuts.h"

const vivid::Vector2 CYellow_Nuts::m_position = { 512.0f,256.0f };

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

	vivid::DrawTexture("data\\forest\\yellow.png", m_position);
}

vivid::Vector2 CYellow_Nuts::GetPosition()
{
	return m_position;
}

CYellow_Nuts& CYellow_Nuts::GetInstance()
{
	static CYellow_Nuts instanse;
	return instanse;//インスタンスを返す
}


