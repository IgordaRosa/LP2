#ifndef CLASSE_HPP
#define CLASSE_HPP
#include "personagem.hpp"

using namespace std;

class Classe{
private:

protected:

public:
    float m_atk, m_def, m_vel;
    float m_Matk, m_Mdef, m_Mvel;
    Classe() : m_atk(0), m_def(0), m_vel(0),m_Matk(0), m_Mdef(0), m_Mvel(0) {};
    Classe(float a, float b, float c, float d=0,float e=0, float f=0) : m_atk(a), m_def(b), m_vel(c),m_Matk(d), m_Mdef(e), m_Mvel(f) {};
    ~Classe() {};
};



#endif