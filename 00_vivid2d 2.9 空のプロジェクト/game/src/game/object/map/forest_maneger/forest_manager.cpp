#include "forest_manager.h"
#include"forest/forest.h"


CForest_Manager::CForest_Manager()
{
}

void CForest_Manager::Initialize()
{
	ChangeForest(FOREST_ID::FOREST1);
	m_f_csv = "data/map.csv";
}

void CForest_Manager::Update()
{
	if (m_ForestID != m_Next_ForestID)
	{
		_ChangeForest();

		switch (m_ForestID)
		{
		case FOREST_ID::DUMMY:
			break;
		case FOREST_ID::FOREST1:
			m_f_csv = "data/map.csv";
			break;
		case FOREST_ID::FOREST2:
			m_f_csv = "data/map2.csv";
			break;
		default:
			break;
		}
		CForest::GetInstance().Fopen();
	}
}

void CForest_Manager::ChangeForest(FOREST_ID fi)
{
	
	m_Next_ForestID = fi;
}

void CForest_Manager::_ChangeForest()
{//シーンIDの更新
	m_ForestID = m_Next_ForestID;
}

CForest_Manager& CForest_Manager::GetInstance()
{
	static CForest_Manager instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

const char* CForest_Manager::GetMapName()
{
	return m_f_csv;
}
