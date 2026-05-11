#pragma once
#include"..\gamemain.h"
#include "../../scene.h"

//story状態
enum class STORY_ID
{
	OPNING,	//オープニング
	STORY1,//ステージ１のストーリー
	ENDING,//エンディング
};

//親クラスはCGamemain
class CStory :public CGamemain
{
public:
	void Initialize(void)override;
	void Update(void)override;
	void Draw(void)override;
	void Finalize(void)override;


	//インスタンス呼び出す
	static CStory& GetInstance();

	//storyの切り替え
	void Change(STORY_ID id);

	void _ChangeStory();

	//ストーリー分岐
	void Opning(void);

	void Story1(void);
		
	IScene* m_Story;
	STORY_ID m_Current_StoryID;//現在のシーンID
	STORY_ID m_Next_StoryID;//次のシーン

private:

	//コンストラクタ
	CStory(); //なにもしない

	//デストラクタ
	~CStory() = default;

	//どこからでも呼び出せるようにする
	CStory(const CStory& rhs) = delete;//コピーの禁止
	CStory& operator =(const CStory& rhs) = delete;//代入の禁止

};