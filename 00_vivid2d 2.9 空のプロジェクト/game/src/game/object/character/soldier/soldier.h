#pragma once
/* 兵士 */
#include"../character.h"

class CSoldier :public CCharacter
{
public:
	CSoldier(void);
	~CSoldier(void) = default;

	void Initialize(void) override;

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;
};