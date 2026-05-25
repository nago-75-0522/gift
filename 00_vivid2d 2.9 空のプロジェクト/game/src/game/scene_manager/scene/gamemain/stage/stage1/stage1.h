#pragma once
#include"..\stage_manager.h"

class CStage1 :public CGamemain
{
public:

	//インスタンス呼び出す
	static CStage1& GetInstance();

	CStage1(void) = default;
	~CStage1(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

};