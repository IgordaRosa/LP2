#include "char.hpp"

void Char::AtualizarStatus(){
	m_atk = m_classe->m_atk * m_classe->m_Matk * m_level;
	m_def = m_classe->m_def * m_classe->m_Mdef * m_level;
	m_vel = m_classe->m_vel * m_classe->m_Mvel * m_level;
}

void Char::LevelUP()
{
	m_level+=1;
	AtualizarStatus();
}

void Char::operator+=(size_t a)
{
	m_dinheiro += a;
}

Char::~Char()
{
	delete m_personagem;
	delete m_classe;
}
