//森
#include"forest.h"
#include"../../../character/protagonist/protagonist.h"
#include"../forest_manager.h"

const int CForest::m_map_chip_size = 64;
const int CForest::m_map_chip_count_width= vivid::WINDOW_WIDTH / m_map_chip_size;
const int CForest::m_map_chip_count_height = vivid::WINDOW_HEIGHT / m_map_chip_size+1;

constexpr int width = 64;
constexpr int height=64;
unsigned char m_Map[height][width];


CForest::CForest(void)
{
}

void CForest::Initialize(void)
{
	CForest_Manager::GetInstance().Initialize();
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			m_Map[i][k]=(unsigned char)MAP_CHIP_ID::EMPTY;
		}
	}
	/*** ファイル操作 ***/
	FILE* fp = nullptr;

	fopen_s(&fp, CForest_Manager::GetInstance().GetMapName(), "r");



	//サイズを調べる
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//サイズ分だけの大きさの入れ物を用意する（一時的なデータ）
	char* buf = new char[size];

	// データ（csvファイル内の文字列）を読み込む
	fread(buf, size, 1, fp);

	//ファイルを閉じる（しないと消せなくなる）
	fclose(fp);

	/*** データの解析 ***/
	//データのサイズ分繰り返し
	for (int i = 0, k = 0; i < size; ++i)
	{
		//文字の０～３であれば、数値に変換する
		if (buf[i] >= '0' && buf[i] <= '6')
		{
			char t = buf[i];

			//データ入力
			m_Map[k / m_map_chip_count_width][k % m_map_chip_count_width]
				= (unsigned char)atoi(&t);

			++k;
		}
	}

	//一時的なデータを削除
	delete[] buf;
}

void CForest::Update(void)
{
	namespace keyboard = vivid::keyboard;
	int x = (int)((CProtagonist::GetInstance().GetCharaPos().x + 0.5f) / (float)m_map_chip_size);
	int y = (int)((CProtagonist::GetInstance().GetCharaPos().y + 0.5f) / (float)m_map_chip_size);


	if (CheckChangeOver1(x, y) &&Button(vivid::keyboard::KEY_ID::W))
	{
	}

	if (CheckChangeOver2(x, y) && Button(vivid::keyboard::KEY_ID::D))
	{
		CForest_Manager::GetInstance().ChangeForest(FOREST_ID::FOREST2);
	}
	
	if (CheckChangeOver3(x, y) && Button(vivid::keyboard::KEY_ID::S))
	{
		CForest_Manager::GetInstance().ChangeForest(FOREST_ID::FOREST3);
	}
	if (CheckChangeOver4(x, y) && Button(vivid::keyboard::KEY_ID::A))
	{
	}

	if (CheckBack(x, y))
	{
		if( vivid::keyboard::Button(vivid::keyboard::KEY_ID::A))
		CForest_Manager::GetInstance().ChangeForest(FOREST_ID::FOREST1);
		else if( vivid::keyboard::Button(vivid::keyboard::KEY_ID::W))
			CForest_Manager::GetInstance().ChangeForest(FOREST_ID::FOREST2);
	}
	CForest_Manager::GetInstance().Update();
}

void CForest::Draw(void)
{
	vivid::DrawTexture("data//field.png", {0.0,0.0 });

	//要素数分繰り返す
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			//位置を求める
			vivid::Vector2 pos;

			pos.x = (float)(k * m_map_chip_size);
			pos.y = (float)(i * m_map_chip_size);

			//読み込み範囲を求める
			vivid::Rect rect;

			rect.left = m_Map[i][k] * m_map_chip_size;
			rect.right = rect.left + m_map_chip_size;
			rect.top = 0;
			rect.bottom = m_map_chip_size;

			//描画
			vivid::DrawTexture("data\\map_chip.png", pos, 0xffffffff, rect);
		}
	}

	
}



void CForest::Fopen(void)
{
	/*** ファイル操作 ***/
	FILE* fp = nullptr;

	fopen_s(&fp, CForest_Manager::GetInstance().GetMapName(), "r");



	//サイズを調べる
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//サイズ分だけの大きさの入れ物を用意する（一時的なデータ）
	char* buf = new char[size];

	// データ（csvファイル内の文字列）を読み込む
	fread(buf, size, 1, fp);

	//ファイルを閉じる（しないと消せなくなる）
	fclose(fp);

	/*** データの解析 ***/
	//データのサイズ分繰り返し
	for (int i = 0, k = 0; i < size; ++i)
	{
		//文字の０～4であれば、数値に変換する
		if (buf[i] >= '0' && buf[i] <= '6')
		{
			char t = buf[i];

			//データ入力
			m_Map[k / m_map_chip_count_width][k % m_map_chip_count_width]
				= (unsigned char)atoi(&t);

			++k;
		}
	}

	//一時的なデータを削除
	delete[] buf;
}


vivid::Vector2 CForest::GetBack()
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			if (m_Map[i][k] == (unsigned char)MAP_CHIP_ID::Back_Space)
			{
				return {
					(float)(k * m_map_chip_size),
					(float)(i * m_map_chip_size)
				};
			}
		}
	}
}

vivid::Vector2 CForest::GetChange1()
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			if (m_Map[i][k] == (unsigned char)MAP_CHIP_ID::Change_Over1)
			{
				return {
					(float)(k * m_map_chip_size),
					(float)(i * m_map_chip_size)
				};
			}
		}
	}
}
vivid::Vector2 CForest::GetChange2()
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			if (m_Map[i][k] == (unsigned char)MAP_CHIP_ID::Change_Over2)
			{
				return {
					(float)(k * m_map_chip_size),
					(float)(i * m_map_chip_size)
				};
			}
		}
	}
}
vivid::Vector2 CForest::GetChange3()
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			if (m_Map[i][k] == (unsigned char)MAP_CHIP_ID::Change_Over3)
			{
				return {
					(float)(k * m_map_chip_size),
					(float)(i * m_map_chip_size)
				};
			}
		}
	}
}

vivid::Vector2 CForest::GetChange4()
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			if (m_Map[i][k] == (unsigned char)MAP_CHIP_ID::Change_Over4)
			{
				return {
					(float)(k * m_map_chip_size),
					(float)(i * m_map_chip_size)
				};
			}
		}
	}
}

int CForest::GetMapChipSize(void)
{
	return m_map_chip_size;
}






bool CForest::CheckWall(int x, int y)
{
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;

	//IDが木なら進めない
	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::TREE)
		return true;
	return false;
}

bool CForest::CheckBack(int x, int y)
{
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;

	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::Back_Space)
		return true;
	return false;
}



bool CForest::CheckChangeOver1(int x, int y)
{
	
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;


	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::Change_Over1)
	  return true;

	return false;
}

bool CForest::CheckChangeOver2(int x, int y)
{
	
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;


	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::Change_Over2)
	  return true;

	return false;
}
bool CForest::CheckChangeOver3(int x, int y)
{
	
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;


	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::Change_Over3)
	  return true;

	return false;
}
bool CForest::CheckChangeOver4(int x, int y)
{
	
	if (x < 0)
		x = 0;
	if (x > m_map_chip_count_width)
		x = m_map_chip_count_width - 1;
	if (y < 0)
		y = 0;
	if (y > m_map_chip_count_height)
		y = m_map_chip_count_height - 1;


	if (m_Map[y][x] == (unsigned char)MAP_CHIP_ID::Change_Over4)
	  return true;

	return false;
}


CForest& CForest::GetInstance()
{
	static CForest instance;//CSceneManager型のインスタンスの作成
	return instance;//インスタンスを返す
}

