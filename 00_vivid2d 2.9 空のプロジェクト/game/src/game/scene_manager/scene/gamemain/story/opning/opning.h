#pragma once
#include"..\story_manager.h"

class COpning :public CGamemain
{
public:

	//インスタンス呼び出す
	static COpning& GetInstance();

	COpning(void) = default;
	~COpning(void) = default;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};