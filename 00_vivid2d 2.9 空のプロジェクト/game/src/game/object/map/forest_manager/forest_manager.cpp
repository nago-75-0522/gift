//森のマップ切り替えの処理
#include "forest_manager.h"
#include"forest/forest.h"
#include"../../character/protagonist/protagonist.h"
#include "fog/fog.h"
#include"fallen_tree/fallen_tree.h"
#include"../../item/key_item/yellow_nuts/yellow_nuts.h"


CForest_Manager::CForest_Manager()
{
}

void CForest_Manager::Initialize()
{
	
	CFallen_Tree::GetInstance().Initialize();
	m_ForestID = FOREST_ID::DUMMY;
	m_Next_ForestID = FOREST_ID::FOREST1;

	_ChangeForest();
	m_fcsv = "data\\forest\\forest1.csv";
	m_State_1 = true;
	m_State_2 = true;
	m_State_3 = true;
	m_State_4 = true;
	m_State_5 = true;
	
}

void CForest_Manager::Update()
{
	if (m_ForestID != FOREST_ID::FOREST4&& m_ForestID != FOREST_ID::FOREST5)
	{
		CFog::GetInstance().Update();
	}
	else if(m_ForestID == FOREST_ID::FOREST4)
	{
		CFog::GetInstance().Initialize();
		CFallen_Tree::GetInstance().Update();
	}
	if (m_ForestID != m_Next_ForestID)
	{
		_ChangeForest();

		switch (m_ForestID)
		{
		case FOREST_ID::DUMMY:
			break;
		case FOREST_ID::FOREST1:
			m_fcsv = "data\\forest\\forest1.csv";
			CForest::GetInstance().Fopen();
			CProtagonist::GetInstance().StopCharacter();
			if (m_State_1 == true)
			{
				CProtagonist::GetInstance().SetBackPosition();
			}
			else 
			{	
				m_State_2 = true;
				CProtagonist::GetInstance().SetChangePosition2();
			}
			
			break;
		case FOREST_ID::FOREST2:
			m_fcsv = "data\\forest\\forest2.csv";
			CForest::GetInstance().Fopen();
			CProtagonist::GetInstance().StopCharacter();

			if (m_State_2 == true)
			{
				m_State_1 = false;
				CProtagonist::GetInstance().SetBackPosition();
			}
			else
			{
				m_State_3 = true;
				CProtagonist::GetInstance().SetChangePosition3();
			}
			
			break;
		case FOREST_ID::FOREST3:
			m_fcsv = "data\\forest\\forest3.csv";
			CForest::GetInstance().Fopen();
			CProtagonist::GetInstance().StopCharacter();

			if (m_State_3 == true)
			{
				m_State_2 = false;
				CProtagonist::GetInstance().SetBackPosition();
			}
			else
			{
				m_State_4 = true;
				CProtagonist::GetInstance().SetChangePosition2();
			}
			break;
		case FOREST_ID::FOREST4:
			m_fcsv = "data\\forest\\forest4.csv";
			CForest::GetInstance().Fopen();
			CProtagonist::GetInstance().StopCharacter();
			if (m_State_4 == true)
			{
				m_State_3 = false;
				CProtagonist::GetInstance().Initialize();
				
			}
			else
			{
				m_State_5 = true;
				CProtagonist::GetInstance().SetChangePosition2();
			}
			break;
		case FOREST_ID::FOREST5:
			m_fcsv = "data\\forest\\forest5.csv";
			CForest::GetInstance().Fopen();
			CProtagonist::GetInstance().StopCharacter();
			if (m_State_5 == true)
			{
				m_State_4 = false;
				CProtagonist::GetInstance().Initialize();

			}
			break;
		default:
			break;
		}
	}
	
}

void CForest_Manager::Draw()
{
	
	//CFog::GetInstance().Draw();
	if (m_ForestID == FOREST_ID::FOREST4)
		CFallen_Tree::GetInstance().Draw();
	if (m_ForestID == FOREST_ID::FOREST5)
		CYellow_Nuts::GetInstance().Draw();
	
}

void CForest_Manager::ChangeForest(FOREST_ID fi)
{
	m_Next_ForestID = fi;
}

void CForest_Manager::_ChangeForest()
{
	//シーンIDの更新
	m_ForestID = m_Next_ForestID;
}

CForest_Manager& CForest_Manager::GetInstance()
{
	static CForest_Manager instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

const char* CForest_Manager::GetMapName()
{
	return m_fcsv;
}
