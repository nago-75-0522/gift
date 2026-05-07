#pragma once
/* 主人公 */


class CProtagonist 
{
public:
	CProtagonist(void);
	~CProtagonist(void) = default;

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);
};