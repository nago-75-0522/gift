#pragma once
#include"..\story_manager.h"


class CStory1 :public CGamemain
{
	public:

	//インスタンス呼び出す
	static CStory1& GetInstance();

	CStory1(void) = default;
	~CStory1(void) = default;

	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;

};