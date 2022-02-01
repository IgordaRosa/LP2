#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct PersonPF
{
    string nome;
    string nomemae;
    string cpf;
    string endereco;
    string telefone;
}; 

PersonPF inserePesssoaPF(size_t fdebug);

struct PersonPJ
{
    string razaosocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalsocial;
};

PersonPJ inserePesssoaPJ(size_t fdebug);

bool LoadDatabase(string path, vector<PersonPF> &PFList, vector<PersonPJ> &PJList);
bool SaveDatabase(string path, const vector<PersonPF> &PFList, const vector<PersonPJ> &PJList);

#endif