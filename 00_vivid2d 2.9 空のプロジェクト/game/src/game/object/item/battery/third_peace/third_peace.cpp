#include"third_peace.h"

const vivid::Vector2 CThird_Peace::position = { 0.0f,0.0f };

void CThird_Peace::Draw(void)
{
	vivid::DrawTexture("data\\parts3.png", position);
}
