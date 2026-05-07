#pragma once
/* 主人公 */


class CProtagonist 
{
public:
	CProtagonist(void);
	~CProtagonist(void) = default;

	void Initialize(void);

	void Update(void);

	void Draw(void);

	void Finalize(void);
private:
	//定数
	static const int m_chara_width;
	static const int m_chara_height;
	static const int m_chara_move_time;
	

	//変数

};
