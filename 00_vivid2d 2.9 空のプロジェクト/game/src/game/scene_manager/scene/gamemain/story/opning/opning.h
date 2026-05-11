#pragma once
#include"..\story_manager.h"

class COpning :public CGamemain
{
public:

	//インスタンス呼び出す
	static COpning& GetInstance();

	COpning(void) = default;
	~COpning(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

};