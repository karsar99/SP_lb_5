#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <random>

using namespace std;

void *thread_func(void *arg){
        int i = * (int *) arg;
        cout << "Номер шара:\t" << i << endl;

        random_device rd;
        mt19937 mersenne(rd());

        srand(mersenne());
        int x = -50 + rand() % 100;
        int y = -50 + rand() % 100;

        cout << "\nНачальная координата:\tx = " << x << "\ty = " << y << endl;

        while(x > -100 && x < 100 && y > -100 && y < 100){
                x += - 50 + rand() % 100;
                y += - 50 + rand() % 100;
                cout << "\nСледующий шаг: x = " << x << "\ty = " << y;
        }
        cout << "\nШар [" << i << "] Убит\n";

}


int main(){
        int number, status;
        cout << "\nВведите номер шара: ";
        cin >> number;

        for(int i = 1; i < number + 1; ++i){
                pthread_t tid;
                pthread_attr_t attr;
                pthread_attr_init(&attr);
                pthread_create(&tid,&attr,thread_func,&i);
                pthread_join(tid,NULL);
        }

        return 0;
}
