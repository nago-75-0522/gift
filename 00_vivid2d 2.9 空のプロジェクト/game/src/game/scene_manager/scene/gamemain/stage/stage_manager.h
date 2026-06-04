#pragma once
#include"..\gamemain.h"
#include "../../scene.h"

//stage状態
enum class STAGE_ID//ステージ
{
	//切り替えるシーン
	STAGE1,		//花畑
	STAGE2,		//海岸
	STAGE3,		//森
	STAGE4,		//町
	STAGE5,		//お城内
	MAX,		//最大値
};

//親クラスはCGamemain
class CStage :public CGamemain
{
public:
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;


	//インスタンス呼び出す
	static CStage& GetInstance();
	//コンストラクタ
	CStage(); //なにもしない

	//デストラクタ
	~CStage() = default;


	//STAGEの切り替え
	void ChangeStage(STAGE_ID id);

	void _ChangeStage();

	IScene* m_Stage;
	STAGE_ID m_Current_StageID;//現在のシーンID
	STAGE_ID m_Next_StageID;//次のシーン

	bool m_IsStoryMode = false;//ステージモードかどうか


private:

	
	//どこからでも呼び出せるようにする
	CStage(const CStage& rhs) = delete;//コピーの禁止
	CStage& operator =(const CStage& rhs) = delete;//代入の禁止

};