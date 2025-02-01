#include <iostream> 
#include <thread>    // manipulação de threads
#include <mutex>     // controle de mutex
using namespace std;

// mutex para sincronização entre threads
mutex mtx;

// Função para a primeira thread
void thread1(int &var1) {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(mtx);  // mutex bloqueado automaticamente
        var1++;
        cout << "Thread 1: var1 = " << var1 << "\n";
    }
}

// Função para a segunda thread
void thread2(int &var2) {
    for (int i = 0; i < 5; i++) { 
        lock_guard<mutex> lock(mtx);  // mutex bloqueado automaticamente
        var2 += 2;
        cout << "Thread 2: var2 = " << var2 << "\n";
    }
}

int main() {
    // Variáveis locais para compartilhar entre as threads
    int var1 = 0;
    int var2 = 0;

    // criação das threads e passando as referências das variáveis
    thread t1(thread1, ref(var1));
    thread t2(thread2, ref(var2));

    // Aguardando as threads terminarem
    t1.join();
    t2.join();

    cout << "Execução finalizada." << "\n";
    cout << "var1 = " << var1 << ", var2 = " << var2 << "\n";

    return 0;
}
