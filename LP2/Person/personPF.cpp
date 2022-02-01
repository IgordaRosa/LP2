#include "personPF.hpp"

PersonPF inserePesssoaPF(size_t fdebug)
{
    PersonPF newPerson;

    if(fdebug) cout << "Enter with a new PF" << endl;
    if(fdebug) cout << "-> Name: ";
    getline(cin, newPerson.nome);

    if(fdebug) cout << "-> Mae: ";
    getline(cin, newPerson.nomemae);

    if(fdebug) cout << "-> CPF: ";
    getline(cin, newPerson.cpf);

    if(fdebug) cout << "-> Endereço: ";
    getline(cin, newPerson.endereco);

    if(fdebug) cout << "-> Telefone: ";
    getline(cin, newPerson.telefone);

    return newPerson;
}

PersonPJ inserePesssoaPJ(size_t fdebug)
{
    PersonPJ newPerson;

    cout << "Enter with a new PJ" << endl;
    cout << "-> Razão Social: ";
    getline(cin, newPerson.razaosocial);

    cout << "-> cnpj: ";
    getline(cin, newPerson.cnpj);

    cout << "-> Endereço: ";
    getline(cin, newPerson.endereco);

    if(fdebug) cout << "-> Telefone: ";
    getline(cin, newPerson.telefone);

    if(fdebug) cout << "-> Capital Social: ";
    //getline(cin, newPerson.capitalsocial);
    size_t capital;
    cin >> capital;
    newPerson.capitalsocial = capital;

    return newPerson;
}

bool LoadDatabase(string path, vector<PersonPF> &PFList, vector<PersonPJ> &PJList){
    ifstream filereader;
    filereader.open(path);
    
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp =="1"){
            PersonPF p;
            getline(filereader, p.nome);
            getline(filereader, p.nomemae);
            getline(filereader, p.cpf);
            getline(filereader, p.endereco);
            getline(filereader, p.telefone);
            PFList.push_back(p);
        }
        else{
            PersonPJ p;
            string a;
            getline(filereader, p.razaosocial);
            getline(filereader, p.cnpj);
            getline(filereader, p.endereco);
            getline(filereader, p.telefone);
            getline(filereader, a);
            size_t capital= stoi(a);
            p.capitalsocial= capital;

            
            PJList.push_back(p);
        }
    }

    filereader.close();

    return true;
}

bool SaveDatabase(string path,const vector<PersonPF> &PFList, const vector<PersonPJ> &PJList){
    ofstream filewrite(path);
    PersonPF p;
    PersonPJ q;


    for(PersonPF p : PFList)
    {
        filewrite << "1" << endl;
        filewrite << p.nome<< endl;
        filewrite << p.nomemae << endl;
        filewrite << p.cpf << endl;
        filewrite << p.endereco<< endl;
        filewrite << p.telefone << endl;
    }

    for(PersonPJ q : PJList)
    {
        filewrite << "2" << endl;
        filewrite << q.razaosocial << endl;
        filewrite << q.cnpj << endl;
        filewrite << q.endereco<< endl;
        filewrite << q.telefone << endl;
        filewrite << q.capitalsocial << endl;
    }

    return true;
}