#pragma once
#include"..\story_manager.h"
#pragma once

class CStory2 :public CGamemain
{
public:

	//インスタンス呼び出す
	static CStory2& GetInstance();
	
	CStory2(void) = default;
	~CStory2(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

};