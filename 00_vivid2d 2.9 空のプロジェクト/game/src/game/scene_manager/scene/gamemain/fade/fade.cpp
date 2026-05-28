#include"fade.h"
#include"vivid.h"

//定数
const float Fade::m_Alpha = 255.0f;		//透明度
float Fade::m_Fade_Speed = 10.0f;	//フェードスピード

//初期化
void Fade::Initialize(void)
{
	m_Fade_State = FADE_STATE::NOTHING;//フェードの状態
	
}

//更新
void Fade::Update(void)
{

}

//描画
void Fade::Draw(void)
{

	// 黒い四角を透明度付きで描画
	unsigned int color = ((unsigned int)m_Alpha << 24) | 0x000000;

	
}

//フェードイン　透明から黒
void Fade::FadeIn(void)
{
	/*m_Fade_State = FADE_STATE::FADE_OUT;
	m_Alpha = 0.0f;    // 最初は透明
	*/
}

//フェードアウト　黒から透明
void Fade::FadeOut(void)
{
	/*m_Fade_State = FADE_STATE::FADE_IN;
	m_Alpha = 255.0f;  // 最初は真っ黒
	*/
	