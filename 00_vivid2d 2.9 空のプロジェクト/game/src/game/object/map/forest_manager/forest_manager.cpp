//森のマップ切り替えの処理
#include "forest_manager.h"
#include"forest/forest.h"
#include"../../character/protagonist/protagonist.h"

CForest_Manager::CForest_Manager()
{
}

void CForest_Manager::Initialize()
{
	ChangeForest(FOREST_ID::FOREST1);
	m_f_csv = "data/forest/forest1.csv";
	m_state_1 = true;
	m_state_2 = true;
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
			m_f_csv = "data/forest/forest1.csv";
			CForest::GetInstance().Fopen();
			if (m_state_1 == true)
			{
				CProtagonist::GetInstance().Initialize();
			}
			else 
			{	
				m_state_2 = true;
				CProtagonist::GetInstance().SetChangePosition2();
			}
			
			break;
		case FOREST_ID::FOREST2:
			m_f_csv = "data/forest/forest2.csv";
			CForest::GetInstance().Fopen();
			if (m_state_2 == true)
			{
				m_state_1 = false;
				CProtagonist::GetInstance().SetBackPosition();
			}
			else
			{
				CProtagonist::GetInstance().SetChangePosition3();
			}
			
			break;
		case FOREST_ID::FOREST3:
			m_f_csv = "data/forest/forest3.csv";
			CForest::GetInstance().Fopen();
			m_state_2 = false;
			CProtagonist::GetInstance().SetBackPosition();
			break;
		default:
			break;
		}
		
		
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
