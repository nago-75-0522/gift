#pragma once
/* 主人公 */
#include"../character.h"

class CProtagonist :public CCharacter
{
public:
	CProtagonist(void);
	~CProtagonist(void);

	void Initialize(void) override;

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;
};