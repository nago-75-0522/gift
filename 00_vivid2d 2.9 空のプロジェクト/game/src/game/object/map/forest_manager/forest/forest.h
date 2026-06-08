#pragma once
#include"vivid.h"
#include"forest_id.h"
class CForest
{
public:
	
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Fopen(void);
	vivid::Vector2 GetBack();
	vivid::Vector2 GetChange1();
	vivid::Vector2 GetChange2();
	vivid::Vector2 GetChange3();
	vivid::Vector2 GetChange4();
	int GetMapChipSize(void);
	
	
	//引数のマス目の場所が壁かどうかを調べる
	bool CheckWall(int x, int y);
	bool CheckBack(int x, int y);
	bool CheckChangeOver1(int x,int y);
	bool CheckChangeOver2(int x, int y);
	bool CheckChangeOver3(int x, int y);
	bool CheckChangeOver4(int x, int y);
	bool CheckInvisivleWall(int x, int y);
	static CForest& GetInstance();
private:

	CForest(void);
	//コピーコンストラクタ
	CForest(const CForest& rhp) = delete;

	CForest& operator=(const CForest& rhp) = delete;

	~CForest(void) = default;

	//定数

	static const int m_map_chip_size;
	static const int m_map_chip_count_width;
	static const int m_map_chip_count_height;
	

	//変数
	enum class MAP_CHIP_ID
	{
		EMPTY,
		TREE,
		Change_Over1,//上
		Change_Over2,//右
		Change_Over3,//左
		Change_Over4,//下
		Back_Space,
		Invisible_Wall
	};
	MAP_CHIP_ID map_chip;
	
	
	FOREST_ID forest_id;
																																																																				
};