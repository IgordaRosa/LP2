#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP
#include <iostream>
#include <string>
#include <vector> 
#include <fstream>

using namespace std;

class Personagem{
private:

protected:

public:
    float m_altura;
    string m_name, m_cpele, m_cabelo, m_ccabelo, m_genero;  
    Personagem() : m_altura(0), m_name(""), m_cpele(""), m_cabelo(""), m_ccabelo(""), m_genero("") {};
    Personagem( string b, float a, string c, string d, string e, string f) : m_altura(a), m_name(b), m_cpele(c), m_cabelo(d), m_ccabelo(e), m_genero(f) {};
    ~Personagem() {};
};

#endif
