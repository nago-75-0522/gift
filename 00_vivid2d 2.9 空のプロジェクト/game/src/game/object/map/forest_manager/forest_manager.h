#pragma once
#include"forest/forest_id.h"
class CForest_Manager
{
public:
	
	void Initialize();
		void Update();
		void ChangeForest(FOREST_ID fi);
		void _ChangeForest();
		static CForest_Manager& GetInstance();

		bool m_state_1;
		bool m_state_2;

		const char* GetMapName();
private:
	const char* m_f_csv;

	//変数
	FOREST_ID m_ForestID;
	FOREST_ID m_Next_ForestID;

	CForest_Manager(void);
	//コピーコンストラクタ
	CForest_Manager(const CForest_Manager& rhp) = delete;

	CForest_Manager& operator=(const CForest_Manager& rhp) = delete;

	~CForest_Manager(void) = default;

};