#include "second_peace.h"

const vivid::Vector2 CSecond_Peace::position = { 0.0f,0.0f };

void CSecond_Peace::Draw(void)
{
	vivid::DrawTexture("data\\parts2.png", position);
}
