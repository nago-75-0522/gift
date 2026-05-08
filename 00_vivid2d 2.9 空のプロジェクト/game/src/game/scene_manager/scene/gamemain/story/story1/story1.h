#pragma once

class CStory1
{

public:
	CStory1(void) = default;
	~CStory1(void) = default;

	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	//インスタンス呼び出す
	static CStory1& GetInstance();

};