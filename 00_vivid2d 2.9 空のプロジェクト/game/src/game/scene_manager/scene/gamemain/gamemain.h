#pragma once
#include"..\scene.h"

class CGamemain :public IScene
{
public:

	//初期化
	void Initialize(void)override;//多重定義
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

	void Menu(void);
	
	void DrawMenu(void);//描画用の関数

	CGamemain(void) = default;//コンストラクタ
	~CGamemain(void) = default;//デストラクタ

	
private:
	//選択できるボタン
	enum class SELECT_BUTTON
	{
		START,	//スタート
		CONTINUED,//続きから
		MAX,	//最大値
		
	};

	//ゲームプレイの状態
	enum class GAME_STATE
	{
		MENU,	//menu画面
		STORY,	//ストーリー
		STAGE,	//ステージ
		MAX,	//最大値
	};

	static const vivid::Vector2 m_BG_Position;						//タイトル画面の画像位置
	static const int m_Button_x[(int)SELECT_BUTTON::MAX];			//ボタンのx座標
	static const int m_Button_y;									//ボタンのy座標
	static const int m_Finger_Width;								//選択印(指)の幅
	static const std::string m_Button_Image[(int)SELECT_BUTTON::MAX];//ボタン画像名
	static const unsigned int m_Select_Button_Color;				//選択中用の色

	

	vivid::Vector2 m_Button_Position;	//ボタンの座標
	vivid::Vector2 m_Finger_Position;	//選択印(指)の座標
	SELECT_BUTTON m_Now_Select = SELECT_BUTTON::MAX;//選択中のボタン
	GAME_STATE m_Now_GameState = GAME_STATE::MAX;//現在のgameの状態
};
