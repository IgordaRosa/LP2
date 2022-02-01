#ifndef IMP_HPP
#define IMP_HPP
#include "char.hpp"

void ImprimirInfo(Char ch){
    cout << "-------------------------------" <<  endl <<  "Informacoes do Char:" << endl;

    size_t sizet = ch.GetCharLevel();
    string st = ch.GetCharName();
    cout <<"Nome: " << st << "  (level: " << sizet << " )"<< endl;

    float fl = ch.GetCharAltura();
    cout <<"Altura: " << fl << endl;

    st = ch.GetCharCpele();
    cout <<"Cor da pele: " <<st << endl;

    st = ch.GetCharCabelo();
    cout <<"Cabelo: " <<st << endl;

    st = ch.GetCharCcabelo();
    cout <<"Cor do cabelo: " <<st << endl;

    st = ch.GetCharGenero();
    cout <<"Genero: " <<st << endl;

    fl = ch.GetCharDin();
    cout <<"Dinheiro: " << fl << endl;
    
    cout << "-------------------------------" << endl;

    fl = ch.GetCharATK();
    cout <<"Ataque: " << fl << endl;

    fl = ch.GetCharDEF();
    cout <<"Defesa: " << fl << endl;

    fl = ch.GetCharVEL();
    cout <<"Velocidade: " << fl << endl;

    cout << "-------------------------------" << endl;
    cout <<endl<<endl;

};

#endif