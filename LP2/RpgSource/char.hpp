#ifndef CHAR_HPP
#define CHAR_HPP
#include "classe.hpp"

using namespace std;

class Char : public Classe
{
private:

protected:
	Personagem *m_personagem;
	Classe *m_classe;
	size_t m_idClasse;
    size_t m_level;
	float m_dinheiro;

public:
	Char() : m_personagem(NULL), m_classe(NULL), m_idClasse(0), m_level(0), m_dinheiro(0){};
	Char(Personagem *personagem, Classe *classe, size_t idClasse = 0, size_t level= 1, float dinheiro =0) : m_personagem(personagem), m_classe(classe), m_idClasse(idClasse), m_level(level), m_dinheiro(dinheiro)
    {
        AtualizarStatus();
    };
	~Char(){};

    //GETTERS
    string GetCharName(){return m_personagem->m_name;};
    float GetCharAltura(){return m_personagem->m_altura;};
    string GetCharCpele(){return m_personagem->m_cpele;};
    string GetCharCabelo(){return m_personagem->m_cabelo;};
    string GetCharCcabelo(){return m_personagem->m_ccabelo;};
    string GetCharGenero(){return m_personagem->m_genero;};
    float GetCharATK(){return m_atk;};
    float GetCharDEF(){return m_def;};
    float GetCharVEL(){return m_vel;};
    size_t GetCharLevel(){return m_level;};
    float GetCharDin(){return m_dinheiro;};
	size_t GetCharID(){return m_idClasse;};

    //SETTERS

	void AtualizarStatus()
	{
		m_atk = m_classe->m_atk * m_classe->m_Matk * m_level;
		m_def = m_classe->m_def * m_classe->m_Mdef * m_level;
		m_vel = m_classe->m_vel * m_classe->m_Mvel * m_level;
	};

	void LevelUP()
	{
		m_level+=1;
		AtualizarStatus();
	};

	/*void operator+(size_t a){m_level += a; AtualizarStatus();};

	Char operator-(size_t a){
        if(m_level - a > 0){
            m_level -= a; 
            AtualizarStatus();
		}
	}*/

	void operator+=(size_t a)
	{
		m_dinheiro += a;
	};

	/*Char operator-=(size_t a){
        if(m_dinheiro - a > 0)
            m_dinheiro -= a;
	}

    Char operator>>(Classe *mudarclasse){
        m_classe = mudarclasse;
        AtualizarStatus();
    };

    Char operator<<(Personagem *mudarperso){m_personagem=mudarperso;};

    Char operator<=(Classe *equip){
        m_atk = (m_classe->m_atk + equip->m_atk) * m_classe->m_Matk * m_level;
        m_def = (m_classe->m_def + equip->m_def) * m_classe->m_Mdef * m_level;
        m_vel = (m_classe->m_vel + equip->m_vel) * m_classe->m_Mvel * m_level;
	};*/
};




#endif
