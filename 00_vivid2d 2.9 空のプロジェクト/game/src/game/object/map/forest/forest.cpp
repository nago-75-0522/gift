#include"forest.h"

const int CForest::m_map_chip_size = 48;
const int CForest::m_map_chip_count_width= vivid::WINDOW_WIDTH / m_map_chip_size + 1;
const int CForest::m_map_chip_count_height = vivid::WINDOW_HEIGHT / m_map_chip_size;

constexpr int width=64;
constexpr int height=64;
unsigned char m_Map[height][width];


CForest::CForest(void)
{
}

void CForest::Initialize(void)
{
	for (int i = 0; i < m_map_chip_count_height; ++i)
	{
		for (int k = 0; k < m_map_chip_count_width; ++k)
		{
			m_Map[i][k]=(unsigned char)MAP_CHIP_ID::EMPTY;
		}
	}
	/*** ファイル操作 ***/
	FILE* fp = nullptr;

	//ファイルを開く 「r」は読み取り
	fopen_s(&fp, "data\\map.csv", "r");

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
		if (buf[i] >= '0' && buf[i] <= '3')
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
}

void CForest::Draw(void)
{
	vivid::DrawTexture("data//field.png", { 0.0,0.0 });

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

bool CForest::CheckGoal(int x, int y)
{
	return false;
}
