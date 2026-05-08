#pragma once
#include"vivid.h"
class CForest
{
public:
	CForest(void);
	~CForest(void) = default;
	void Initialize(void);
	void Update(void);
	void Draw(void);
	//引数のマス目の場所が壁かどうかを調べる
	bool CheckWall(int x, int y);

	//ゴールチェック
	bool CheckGoal(int x, int y);
	

private:


	enum class MAP_CHIP_ID
	{
		EMPTY,
		TREE,
        START_FLAG,
		GOAL_FLAG
	};
	MAP_CHIP_ID map_chip;
	//定数

	static const int m_map_chip_size;
	static const int m_map_chip_count_width;
	static const int m_map_chip_count_height;

	
	
};