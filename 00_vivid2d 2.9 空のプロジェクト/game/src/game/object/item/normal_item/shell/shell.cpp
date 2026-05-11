#include"shell.h"

const int CShell::m_max_shell = 8;

CShell::CShell(void)
	:m_Shells(nullptr)
{
}

void CShell::Initialize(void)
{
	m_Shells = new SHELL[m_max_shell];

	m_Shells[0].m_Position = { 0.0f,0.0f };
	m_Shells[1].m_Position = { 0.0f,0.0f };
	m_Shells[2].m_Position = { 0.0f,0.0f };
	m_Shells[3].m_Position = { 0.0f,0.0f };
	m_Shells[4].m_Position = { 0.0f,0.0f };
	m_Shells[5].m_Position = { 0.0f,0.0f };
	m_Shells[6].m_Position = { 0.0f,0.0f };
	m_Shells[7].m_Position = { 0.0f,0.0f };
}

void CShell::Draw(void)
{
	for (int i = 0;i < m_max_shell;++i)
	{
		vivid::DrawTexture("data\\shell.png", m_Shells[i].m_Position);
	}
}

void CShell::Finalize(void)
{
	delete[] m_Shells;

	m_Shells = nullptr;
}
