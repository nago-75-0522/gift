#pragma once
#include"forest/forest_id.h"
class CForest_Manager
{
public:
	
	void Initialize();
		void Update();
		void Draw();
		void ChangeForest(FOREST_ID fi);
		void _ChangeForest();
		static CForest_Manager& GetInstance();

		FOREST_ID GetID() { return m_ForestID; };
		
		const char* GetMapName();
private:
	
	

	

	CForest_Manager(void);
	//コピーコンストラクタ
	CForest_Manager(const CForest_Manager& rhp) = delete;

	CForest_Manager& operator=(const CForest_Manager& rhp) = delete;

	~CForest_Manager(void) = default;
	//定数
	const char* m_fcsv;

	//変数
	FOREST_ID m_ForestID;
	FOREST_ID m_Next_ForestID;

	bool m_State_1;
	bool m_State_2;
	bool m_State_3;
	bool m_State_4;
	bool m_State_5;

};