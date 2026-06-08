#pragma once
#include"vivid.h"
//倒木
class CFallen_Tree
{
public:

	void Initialize();
	void Update();
	void Draw();
	vivid::Vector2 GetTreePos1();
	vivid::Vector2 GetTreePos2();
	vivid::Vector2 GetTreePos3();
	static CFallen_Tree& GetInstance();

private:
	CFallen_Tree(void);
	//コピーコンストラクタ
	CFallen_Tree(const CFallen_Tree& rhp) = delete;
	
	CFallen_Tree& operator=(const CFallen_Tree& rhp) = delete;

	~CFallen_Tree(void) = default;	
	//定数
	static const vivid::Vector2 m_tree_roll_velocity;
	static const int m_max_tree;
	static const int m_tree_set_interval;
	//変数
	int            m_Tree_Interval;
	unsigned int   m_Tree_Color;
	vivid::Vector2 m_Tree_Pos_1;
	vivid::Vector2 m_Tree_Pos_2;
	vivid::Vector2 m_Tree_Pos_3;
};