#pragma once
/* 主人公と兵士の親クラス */

class CCharacter
{
public:
	CCharacter(void) = default;
	virtual ~CCharacter(void) = default;

	virtual void Initialize(void) = 0;

	virtual void Update(void) = 0;

	virtual void Draw(void) = 0;

	virtual void Finalize(void) = 0;
};
