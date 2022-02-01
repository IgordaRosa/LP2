#include "personPF.hpp"
#include <iostream>
#include <vector>
#include <fstream>

#define fdebug 1

int main()
{
    vector<PersonPF> PFList;
    vector<PersonPJ> PJList;


    if(LoadDatabase("database.dat", PFList, PJList)== false){
        cout << " Database file not found. Creating a new one" << endl;
    }

    for(;;)
    {
        SaveDatabase("database.dat", PFList, PJList);

        if(fdebug) cout << "MY PAPA'S COMPANY - SIG" << endl;
        if(fdebug) cout << "1. Add PF..." << endl;
        if(fdebug) cout << "2. Add PJ..." << endl;
        if(fdebug) cout << "3. Remove PF Index..." << endl;
        if(fdebug) cout << "4. Remove PJ Index..." << endl;
        if(fdebug) cout << "5. Print Names in Ascending Order" << endl;
        if(fdebug) cout << "6. Exit" << endl;
        if(fdebug) cout << "Enter an option: " << endl;

        char ch;
        cin >> ch;


        //clear input buffer
        cin.ignore();  //fflush();

        if(ch == '1')
        {
            PersonPF p1 = inserePesssoaPF(fdebug);
            PFList.push_back(p1);
            continue;
        }
        //cin.ignore();
        if(ch == '2')
        {
            PersonPJ p1 = inserePesssoaPJ(fdebug);
            PJList.push_back(p1);
            continue;
        }
        if(ch == '3')
        {
            cout << "Digite a PF que deseja remover: ";
            size_t remover;
            cin >> remover;
            PFList.erase(PFList.begin() + remover);
            continue;

        }
        if(ch == '4')
        {
            cout << "Digite a PF que deseja remover: ";
            size_t remover;
            cin >> remover;
            PJList.erase(PJList.begin() + remover);
            continue;
        }
        if(ch == '5')
        {
            vector< string > armazenamento;
            for(size_t i=0;i<PFList.size();i++){
                armazenamento.push_back(PFList.at(i).nome);
            }
            for(size_t i=0;i<PJList.size();i++){
                armazenamento.push_back(PJList.at(i).razaosocial);
            }
            cout << "Names in Ascending Order: " << endl;
            sort(armazenamento.begin(), armazenamento.end());
            
            for(size_t i=0; i<armazenamento.size();i++){
                cout << armazenamento.at(i) << endl;
            }

            continue;
        }
        if(ch == '6')
        {
            break;
        }
        else{
            continue;
        }  
    }

    return 0;
}



