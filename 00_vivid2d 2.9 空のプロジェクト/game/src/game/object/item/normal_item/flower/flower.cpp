#include"flower.h"

const int CFlower::m_max_flower = 10;

CFlower::CFlower(void)
	:m_Flowers(nullptr)
{
}

void CFlower::Initialize(void)
{
	m_Flowers = new FLOWER[m_max_flower];

	m_Flowers[0].m_Position = { 0.0f,0.0f };
	m_Flowers[1].m_Position = { 0.0f,0.0f };
	m_Flowers[2].m_Position = { 0.0f,0.0f };
	m_Flowers[3].m_Position = { 0.0f,0.0f };
	m_Flowers[4].m_Position = { 0.0f,0.0f };
	m_Flowers[5].m_Position = { 0.0f,0.0f };
	m_Flowers[6].m_Position = { 0.0f,0.0f };
	m_Flowers[7].m_Position = { 0.0f,0.0f };
	m_Flowers[8].m_Position = { 0.0f,0.0f };
	m_Flowers[9].m_Position = { 0.0f,0.0f };
}

void CFlower::Draw(void)
{
	for (int i = 0;i < m_max_flower;++i)
	{
		vivid::DrawTexture("data\\flower.png", m_Flowers[i].m_Position);
	}
}

void CFlower::Finalize(void)
{
	delete[] m_Flowers;

	m_Flowers = nullptr;
}
