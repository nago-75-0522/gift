#pragma once

class CGame
{
public:
	CGame(void) = default;
	~CGame(void) = default;
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);
};