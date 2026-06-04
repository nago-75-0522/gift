#pragma once
#include"..\scene.h"
#include"vivid.h"
#include"..\gamemain\stage\stage_manager.h"


class CSave :public IScene
{
public:

	//インスタンス呼び出す
	static CSave& GetInstance();

	//初期化
	void Initialize(void)override;//多重定義
	//更新
	void Update(void)override;
	//描画
	void Draw(void)override;
	//解放
	void Finalize(void)override;

	void SaveSelect(void);
	

	CSave(void) = default;//コンストラクタ
	~CSave(void) = default;//デストラクタ

private:
	static const vivid::Vector2 m_BG_Position;						//タイトル画面の画像位置
	static const int m_Finger_Width;								//選択印(指)の幅
	static const std::string m_Button_Image[(int)STAGE_ID::MAX];//ボタン画像名
	static const unsigned int m_Select_Button_Color;				//選択中用の色

	vivid::Vector2 m_Button_Position;	//ボタンの座標
	vivid::Vector2 m_Finger_Position;	//選択印(指)の座標
	STAGE_ID m_Now_Select = STAGE_ID::MAX;//選択中のボタン

	//SAVE_STATE m_Now_Save_State = SAVE_STATE::MAX;//現在のsaveの状態

	/*	キーボード */
	static const int m_Button_x[(int)STAGE_ID::MAX];			//ボタンのx座標
	static const int m_Button_y;									//ボタンのy座標

	/* コントローラー */
	vivid::Vector2 m_Stic;//スティックx左右 y上下


};