#pragma once
/* 黄色の木の実 */
#include"vivid.h"

class CYellow_Nuts
{
public:
	
	void Initialize(void);
	void Draw(void);

	vivid::Vector2 GetPosition();
	static CYellow_Nuts& GetInstance();

private:
	CYellow_Nuts(void);
	//コピーコンストラクタ
	CYellow_Nuts(const CYellow_Nuts& rhp) = delete;

	CYellow_Nuts& operator=(const CYellow_Nuts& rhp) = delete;

	~CYellow_Nuts(void) = default;

	static const vivid::Vector2 m_position;
	
	bool m_isHitFlag; //採ったかどうか
};