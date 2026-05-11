#pragma once
/* 普通の貝殻（白？） */
#include"vivid.h"

class CShell
{
public:
	CShell(void);
	~CShell(void) = default;

	void Initialize(void);

	void Draw(void);

	void Finalize(void);
private:
	//一つ一つの情報
	struct SHELL
	{
		vivid::Vector2 m_Position;
		bool m_isHitFlag;//採ったかどうか
	};
	SHELL* m_Shells;

	static const int m_max_shell;//貝の最大数


};