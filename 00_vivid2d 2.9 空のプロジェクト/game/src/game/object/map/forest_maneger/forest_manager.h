#pragma once
#include"forest/forest_id.h"
class CForest_Manager
{
public:
	CForest_Manager();
	~CForest_Manager() = default;
	void Initialize();
		void Update();
		void ChangeForest(FOREST_ID fi);
		void _ChangeForest();
		static CForest_Manager& GetInstance();

		const char* GetMapName();
private:
	const char* m_f_csv;

	//変数
	FOREST_ID m_ForestID;
	FOREST_ID m_Next_ForestID;
};