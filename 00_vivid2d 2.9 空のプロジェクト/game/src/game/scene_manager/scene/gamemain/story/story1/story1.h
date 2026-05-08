#pragma once
#include"..\story_manager.h"


class CStory1 :public CGamemain
{
	public:

	//インスタンス呼び出す
	static CStory1& GetInstance();

	CStory1(void) = default;
	~CStory1(void) = default;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

};