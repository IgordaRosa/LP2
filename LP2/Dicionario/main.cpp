#include "biblioteca.hpp"
#include "biblioteca.cpp"

#define Debug 1

int main(){
    setlocale(LC_ALL,"Portuguese");

    vector< vector < string > > ListaDicionario;
    vector< string > ListaDicionarioNomes;
    vector <string> Armazenamento;
    char escolha;

    for(;;){
        if(Debug){
        //cout << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl;
        cout << "|___________________________" << endl << "|" << endl<< "|    Menu do Dicionario" << endl << "|___________________________" << endl;
        cout << "|" << endl << "|  1. Abrir um dicionario..." << endl << "|" << endl << "|  2. Procurar uma Substring..." << endl;
        cout << "|" << endl << "|  3. Remover palavras que contem uma substring..." << endl <<"|" << endl << "|  4. Estatisticas..." << endl << "|" << endl<< "|  5. Sair..." << endl;
        cout << "|" << endl << "|  6. Abrir todos os dicionarios..." << endl << "|" << endl << "|" << endl<< "|" << endl<< "|" << endl<< "|" << endl<< "|" << endl<< "|" << endl<< "|  Op��o: ";
        }

        cin >> escolha;

        //int DA = 0;

        // abrir dicionario
        if(escolha == '1')
        {
            string arquivo;
            if(Debug) {cout << "|  Digite o nome do arquivo: ";}
            cin >> arquivo;
            vector<string> lista;
            if(!LoadDictionary(arquivo, lista)){
                cout << "|           >>>Erro ao ler o arquivo!<<<          " << endl;
            }
            else{
                cout << "|           >>>Sucesso ao ler o arquivo!<<<          " << endl;
                ListaDicionario.push_back(lista);
                ListaDicionarioNomes.push_back(arquivo);
                for(size_t i=0; i < lista.size(); i++){
                    Armazenamento.push_back(lista.at(i));
                }
            }
            
            continue;
        }
    
        // procurar substring
        if(escolha == '2')
        {   
            cout << "|  Digite uma palavra para buscar: " ;
            string procura;
            cin >> procura;
            if(SearchWord(Armazenamento, procura)){
                cout << "|  Existe essa substring!  "<< endl;
                vector< string > sublist = SearchSubstrings(Armazenamento, procura);
                cout << "|  Substring list: -------------------------" << endl;
                for(size_t i=0; i<sublist.size(); i++)
                {
                    cout << "|  " << sublist.at(i) << " --> " << sublist.at(i).length() << endl;
                }
            }
            else{
                cout << "|  Não existe essa substring!  "<< endl;
            }
            continue;
        }

        // remover substring
        if(escolha == '3')
        {
          cout << "|  Digite a substring que deseja remover: ";
          string procura;
          cin >> procura;

          for(size_t i=0; i < ListaDicionario.size(); i++)
          {
              int index = 0;
              for(string str : ListaDicionario.at(i))
              {
                  size_t existe = str.find(procura);

                  if(existe != string::npos)
                  {
                      ListaDicionario.at(i).erase(ListaDicionario.at(i).begin() + index);
                  }
                  index++;
              }
          }
            continue;
        }

        if(escolha == '4'){
            cout << "|  Estatisticas" << endl;
            for(size_t i=0; i < ListaDicionarioNomes.size(); i++)
            {
                cout << "|  " << ListaDicionarioNomes[i] << " --> " << ListaDicionario.at(i).size() << " words" << endl;
            }
            continue;
        }

        if(escolha == '5'){
            break;
        }

        if(escolha == '6'){
            cout << "|  Todos os dicionarios" << endl;
            for(size_t i=0; i < Armazenamento.size(); i++)
            {
                //for(size_t j=0; j < ListaDicionario.at(i).size(); j++)
                {
                    cout << "|  " << i << "  " << Armazenamento.at(i) << " -> " << Armazenamento.at(i).length() << endl; 
                }
            }
            continue;
        }

        else{
            if(Debug){cout << "Não existe esta opção!" << endl;}
            continue;
        }

        
    }
    return 0;   
} 