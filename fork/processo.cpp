#include <iostream>
#include <stdlib.h>   
#include <unistd.h>    //criar e gerenciar processos
#include <sys/types.h> //define pid_t ID
#include <sys/wait.h>  //esperar processos filhos

using namespace std;

int main() {
    //cria novo processo. 
    pid_t pid = fork();

    //verifica se deu erro ao criar processo
    if (pid < 0) {
        perror("fork"); 
        return 1;
    } else if (pid == 0) {  //processo filho
        int num = 17;  //definido um número para verificar se é ímpar ou par

        if (num % 2 == 0) {  //verifica se é par
            cout << "O número " << num << " é par." << "\n";
        } else {  // se não, é ímpar
            cout << "O número " << num << " é ímpar." << "\n";
        }
    } else {  //processo pai
        cout << "Processo pai: Aguarde o resultado do filho..." << "\n";
        wait(NULL); //espera o processo filho terminar.
        cout << "Processo pai: Filho terminou." << "\n"; 
    }
    return 0; //fim do programa
}