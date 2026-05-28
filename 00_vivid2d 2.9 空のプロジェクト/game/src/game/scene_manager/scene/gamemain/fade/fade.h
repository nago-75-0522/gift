#pragma once
//フェード処理のクラス
class Fade
{
public:

	Fade(void) = default;//コンストラクタ

	void Initialize(void);//初期化

	void Update(void);	//更新

	void Draw(void);	//描画

	void FadeIn();	//フェードインの処理　透明から黒

	void FadeOut(); //フェードアウト処理　黒から透明



private:
	enum FADE_STATE
	{
		FADE_IN,	//フェードイン
		FADE_OUT,	//フェードアウト
		NOTHING,	//何もなし
	};

	FADE_STATE m_Fade_State;//フェードの状態
	static const float m_Alpha;//透明度
	static float m_Fade_Speed;//どれくらいで消えていくか
	




};