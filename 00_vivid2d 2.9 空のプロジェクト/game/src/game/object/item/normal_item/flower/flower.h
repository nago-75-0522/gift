#pragma once
/* 普通の花（黄色） */
#include"vivid.h"

class CFlower
{
public:
	CFlower(void);
	~CFlower(void) = default;

	void Initialize(void);

	void Draw(void);

	void Finalize(void);
private:
	//一つ一つの情報
	struct FLOWER
	{
		vivid::Vector2 m_Position;
		bool m_isHitFlag;//採ったかどうか
	};
	FLOWER* m_Flowers;

	static const int m_max_flower;//お花の最大数


};