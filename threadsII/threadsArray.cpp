#include <iostream>  
#include <thread> // para threads
#include <mutex> // para (sincronização)
using namespace std;

int vetor[4] = {0, 0, 0, 0}; // Vetor fixo com 4 posições, inicializado com zeros
mutex mutex0, mutex1, mutex2, mutex3; // Declaração de mutexes para cada posição do vetor
const int NUMERO_ITERACOES = 2000; // Constante com o número de iterações para cada thread

// Função para a Thread1: Incrementa as posições vetor[0] e vetor[1]
void funcao_thread1() {
    for (int i = 0; i < NUMERO_ITERACOES; ++i) { // Loop para realizar as iterações
        lock_guard<mutex> trava0(mutex0); // Trava o mutex para a posição 0
        vetor[0]++; // Incrementa o valor na posição 0 do vetor
        lock_guard<mutex> trava1(mutex1); // Trava o mutex para a posição 1
        vetor[1]++; // Incrementa o valor na posição 1 do vetor

        // Print dos valores das posições 0 e 1 na iteração atual
        cout << "Thread 1 - Iteração " << i + 1 
             << ": vetor[0] = " << vetor[0] 
             << ", vetor[1] = " << vetor[1] << "\n";
    }
}

// Função para a Thread2: Decrementa as posições vetor[1] e vetor[2] 
void funcao_thread2() {
    for (int i = 0; i < NUMERO_ITERACOES; ++i) { // Loop para realizar as iterações
        lock_guard<mutex> trava1(mutex1); // Trava o mutex para a posição 1
        vetor[1]--; // Decrementa o valor na posição 1 do vetor
        lock_guard<mutex> trava2(mutex2); // Trava o mutex para a posição 2
        vetor[2]--; // Decrementa o valor na posição 2 do vetor

        // Print dos valores das posições 1 e 2 na iteração atual
        cout << "Thread 2 - Iteração " << i + 1 
             << ": vetor[1] = " << vetor[1] 
             << ", vetor[2] = " << vetor[2] << "\n";
    }
}

// Função para a Thread3: Incrementa as posições vetor[2] e vetor[3]
void funcao_thread3() {
    for (int i = 0; i < NUMERO_ITERACOES; ++i) { // Loop para realizar as iterações
        lock_guard<mutex> trava2(mutex2); // Trava o mutex para a posição 2
        vetor[2]++; // Incrementa o valor na posição 2 do vetor
        lock_guard<mutex> trava3(mutex3); // Trava o mutex para a posição 3
        vetor[3]++; // Incrementa o valor na posição 3 do vetor

        // Print dos valores das posições 2 e 3 na iteração atual
        cout << "Thread 3 - Iteração " << i + 1 
             << ": vetor[2] = " << vetor[2] 
             << ", vetor[3] = " << vetor[3] << "\n";
    }
}

// Função principal do programa
int main() {
    // Criação das threads, cada uma executando uma função específica
    thread t1(funcao_thread1), t2(funcao_thread2), t3(funcao_thread3);

    // Aguarda todas as threads finalizarem antes de continuar
    t1.join();
    t2.join();
    t3.join();

    // Print final do vetor, depois de todas as operações das threads
    cout << "\nEstado final do vetor:" << "\n";
    for (int i = 0; i < 4; ++i) { // Percorre o vetor para exibir os valores finais
        cout << "vetor[" << i << "] = " << vetor[i] << "\n";
    }

    return 0; // Fim do programa
}
