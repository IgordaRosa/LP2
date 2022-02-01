#include "policy2.hpp"

#define DEBUG 1

int main(){
    Scheduler *job = new Scheduler();
    for(;;){
        if(DEBUG)cout << endl << "TASK SCHEDULER SYSTEM ? UFxC TSS" << endl << endl;
        if(DEBUG)cout << "Select an option below:" << endl;
        if(DEBUG)cout << "1. Schedule a task to process" << endl;
        if(DEBUG)cout << "2. Pick up a task to process using Policy 1" << endl;
        if(DEBUG)cout << "3. Pick up a task to process using Policy 2" << endl;
        if(DEBUG)cout << "4. Print pending tasks" << endl;
        if(DEBUG)cout << "5. Exit" << endl;
        if(DEBUG)cout << "Option: ";
        size_t escolha;
        cin >> escolha;

        if(escolha == 1){
            size_t ID;
            if(DEBUG)cout << endl << "Set ID:";
            cin >> ID;
            if(!job->SetJob(ID)){
                cout << "Error, this id already exists!!" << endl;
            }
            continue;
        }

        if(escolha == 2){// esta opção acontece polimorfismo
            if(DEBUG)cout << endl << "Policy 1 executed: " << endl;
            Policy1 p1(job);//envia a mensagem ao Policy 1, para executar a politica com o Scheduler job
            p1.ExecuteP1();//mensagem para executar, como o Scheduler ja setado, poderia fazer junto ao de cima mas achei melhor separar
            job->ResetJobs(p1.GetVector());// aqui é devolvido o vetor
            continue;
        }

        if(escolha == 3){// esta opção acontece polimorfismo
            if(DEBUG)cout << endl << "Policy 2 executed: " << endl;
            Policy2 p2(job);
            p2.ExecuteP2();//aqui faz a mesma coisa porém muda o valor acessado pro ultimo do vetor
            job->ResetJobs(p2.GetVector());
            continue;
        }
        
        if(escolha == 4){
            vector<size_t> temp = job->GetVector();
            if(DEBUG)cout << endl << "This is a vector:" << endl;
            for(size_t i=0;i< temp.size(); i++){
                cout << i << ".Job " << temp.at(i) << endl;
            }
            continue;
        }

        if(escolha == 5){
            break;
        }

        else{
            continue;
        }    
    }
    delete job;
    return 0;
}