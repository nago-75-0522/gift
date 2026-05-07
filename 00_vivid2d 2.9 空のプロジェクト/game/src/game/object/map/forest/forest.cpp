#include"forest.h"

const int CForest::m_map_chip_size = 48;
const int CForest::m_map_chip_count_width= vivid::WINDOW_WIDTH / m_map_chip_size + 1;
const int CForest::m_map_chip_count_height = vivid::WINDOW_HEIGHT / m_map_chip_size;

CForest::CForest(void)
{
}

void CForest::Initialize(void)
{
	unsigned char m_Map[m_map_chip_count_height][m_map_chip_count_width]
		= { (unsigned char)MAP_CHIP_ID::EMPTY };

}

void CForest::Update(void)
{
}

void CForest::Draw(void)
{

}
