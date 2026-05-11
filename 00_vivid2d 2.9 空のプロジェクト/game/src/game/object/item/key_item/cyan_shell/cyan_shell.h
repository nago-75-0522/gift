#pragma once
/* シアン色の貝殻 */
#include"vivid.h"

class CCyan_Shell
{
public:
	CCyan_Shell(void);
	~CCyan_Shell(void) = default;

	void Initialize(void);

	void Draw(void);
private:
	static const vivid::Vector2 m_position;

	bool m_isHitFlag; //採ったかどうか
};