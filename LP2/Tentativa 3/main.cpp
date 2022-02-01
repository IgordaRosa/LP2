#include "imp.cpp"

int main(){
    cout << "Bem vindo ao RPG do Igor" << endl;

    // defini��es de personagem
    Personagem *a = new Personagem("geraldo", 1.85, "branca", "curto, ondulado", "escura", "masculino");
    Personagem *b = new Personagem("martelo213", 1.75, "pardo", "longo, ondulado", "escura", "masculino");
    Personagem *c = new Personagem("mario",1.65, "moreno", "curto, liso", "loiro", "masculino");

    // defini��es de classes de combate
    Classe *guerreiro = new Classe(70, 100, 50, 1.07, 1.1, 1.05);
    Classe *mago = new Classe(100, 70, 50, 1.1, 1.07, 1.05);

    Classe *equipamento1 = new Classe(10, 7, 5);
    Classe *equipamento2 = new Classe(9, 7, 6);

    // defini��es de characters
    Char conta1(a, guerreiro);
    Char conta2(b, mago, 30);

    // demonstra��o de GETTER individual e fun��o level up
    size_t level = conta2.GetCharLevel();
    cout << level << endl;
    
    conta2.LevelUP();
    
    level = conta2.GetCharLevel();
    cout << level << endl;

    string ver = conta1.GetCharName();
    cout << ver << endl;

    // utiliza��o dos operadores setters
    conta1 + 20; //adi��o de level
    conta1 - 15; //subtra��o de level
    conta1 - 6; //n�o ir� deixar pois � menor que 0

    conta2 += 1000; // adi��o de dinheiro na conta
    conta2 -= 500; // remo��o de dinheiro na conta
    conta2 -= 600; //n�o ir� deixar pois n�o possui esse dinheiro na conta

    conta2 >> guerreiro; //trocar a classe de combate
    conta1 >> mago; //trocar a classe de combate
    
    conta1 << c;//trocar aparencia e nome do personagem(ocorrencia comum em rpgs)

    conta1 <= equipamento1;//adcionar equipamento ao character
    conta2 <= equipamento2;//adcionar equipamento ao character

    // impress�o de infos geral do character
    ImprimirInfo(conta1);
    ImprimirInfo(conta2);


    delete a, b, c, guerreiro, mago, equipamento1, equipamento2;
    return 0;
}