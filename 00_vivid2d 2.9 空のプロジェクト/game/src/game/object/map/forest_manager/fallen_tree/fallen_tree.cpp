#include "fallen_tree.h"
#include"../forest/forest.h"
#include"../../forest_manager/forest_manager.h"
//定数
 const vivid::Vector2 CFallen_Tree::m_tree_roll_velocity = { 10.0,0.0 };//木の転がる速さ
 const int CFallen_Tree:: m_tree_set_interval=60*5;//木が転がり始める時間


CFallen_Tree::CFallen_Tree()
:m_Tree_Interval(0)
,m_Tree_Pos_1(0.0f,0.0f)
,m_Tree_Pos_2(0.0f, 0.0f)
,m_Tree_Pos_3(0.0f, 0.0f)
,m_Tree_Color(0xffffffff)
{
}

void CFallen_Tree::Initialize()
{
	m_Tree_Interval = m_tree_set_interval;
	m_Tree_Pos_1 = { vivid::WINDOW_WIDTH,320.0f };
	m_Tree_Pos_2 = { vivid::WINDOW_WIDTH,384.0f };
	m_Tree_Pos_3 = { vivid::WINDOW_WIDTH,320.0f };
	m_Tree_Color = 0xffffffff;
	
}

void CFallen_Tree::Update()
{	
	
	 if (--m_Tree_Interval<=0)
	{
		m_Tree_Pos_1.x -= m_tree_roll_velocity.x;
	}
	 if (m_Tree_Pos_1.x<=500)
	{
		m_Tree_Pos_2.x -= m_tree_roll_velocity.x;
		
	}
	 if( m_Tree_Pos_2.x <= 800)
		m_Tree_Pos_3.x -= m_tree_roll_velocity.x;
		
}

void CFallen_Tree::Draw()
{
	vivid::DrawTexture("data\\forest\\fallentree.png", m_Tree_Pos_1,m_Tree_Color);
	vivid::DrawTexture("data\\forest\\fallentree.png", m_Tree_Pos_2,m_Tree_Color);
	vivid::DrawTexture("data\\forest\\fallentree.png", m_Tree_Pos_3,m_Tree_Color);
}

vivid::Vector2 CFallen_Tree::GetTreePos1()
{
	return m_Tree_Pos_1;
}
vivid::Vector2 CFallen_Tree::GetTreePos2()
{
	return m_Tree_Pos_2;
}

vivid::Vector2 CFallen_Tree::GetTreePos3()
{
	return m_Tree_Pos_3;
}

CFallen_Tree& CFallen_Tree::GetInstance()
{
	static CFallen_Tree instanse;
	return instanse;//インスタンスを返す
}

