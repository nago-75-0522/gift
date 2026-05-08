#include"story1.h"
#include"vivid.h"

CStory1& CStory1::GetInstance()
{
	static CStory1 instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

void CStory1::Draw(void)
{
	vivid::DrawTexture("data\\story1.png", { 0,0 });

}